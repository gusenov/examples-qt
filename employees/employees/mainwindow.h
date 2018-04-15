#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionCreateNewDatabase_triggered();

    void on_actionOpenDatabase_triggered();

    void on_actionExit_triggered();

    void on_pushButtonAddRecord_clicked();

    void on_pushButtonDeleteRecord_clicked();

    void on_pushButtonShowAllData_clicked();

    void on_pushButtonSortData_clicked();

    void on_pushButtonFilter_clicked();

    void on_pushButtonYearOfAdmissionGreaterThan2010_clicked();

    void on_pushButtonYearOfAdmissionLessThan2011_clicked();

private:
    Ui::MainWindow *ui;

    static const QString fileDialogFilterString;

    QSqlDatabase m_db;  // объект базы данных.
    QSqlQuery *query;  // указатель на запрос.
    QSqlTableModel *model;  // указатель на таблицу данных в приложении.

    void initAppWithDatabaseFile(const QString &dbFileFullPath);
    void connectToDatabase(const QString &dbName = QString("db"));
    void createModel();
    void setUserInterfaceEnabled(bool isEnanbled);
};

#endif // MAINWINDOW_H
