#pragma once

#include <QWidget>
#include <QSettings>

class QComboBox;
class QCheckBox;
class QTextEdit;
class QLabel;

// ======================================================================
class MyProgram : public QWidget {
Q_OBJECT
private:
    QSettings  m_settings;
    QComboBox* m_pcbo;      // виджет выпадающего списка
    QCheckBox* m_pchk;      // флажок
    QTextEdit* m_ptxt;      // виджет текстового поля
    QLabel*    m_plbl;      // виджет надписи
    int        m_nCounter;  // счетчик количества запусков программы

public:
    MyProgram(QWidget* pwgt = 0);
    virtual ~MyProgram();

    // Методы для записи и чтения данных настроек программы:
    void writeSettings();
    void readSettings();

    void removeSettings();

public slots:
    // Слоты для выполнения действий,
    // вызываемых изменением состояний флага и выпадающего списка:
    void slotCheckBoxClicked();
    void slotComboBoxActivated(int);
};

