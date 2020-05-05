#include <QApplication>
#include <QSettings>

// В больших проектах целесообразно обращаться к объекту настроек приложения централизованно.
// Дпя этого можно унаследовать класс QApplication и инкапсулировать объект
// настроек в нем.

class App : public QApplication {
Q_OBJECT
private:
    // В Qt для работы с настройками служит класс QSettings.
    QSettings* m_pSettings;

public:
    App(int& argc,    // делегируем переменные argc,
        char** argv,  // argv унаследованному классу QApplication.
        const QString& strOrg,     // имя организации
        const QString& strAppName  // название приложения
       ) : QApplication(argc , argv)
         , m_pSettings(nullptr)
    {
        // Если настройки должны использоваться в нескольких местах, то лучще централизованно
        // установить имя компании и название программы, для чего в классе QCoreApplication определены
        // статические методы setOrganisationNarne() и setApplicationName():
        QCoreApplication::setOrganizationName(strOrg);
        QCoreApplication::setApplicationName(strAppName);

        // При создании в конструктор
        // можно передать имя компании и название программы:
        m_pSettings = new QSettings(strOrg , strAppName, this);
    }

    // Статический метод theApp() нам нужен для того, чтобы
    // получать доступ к объекту нашего приложения из любой библиотеки проекта.
    static App* theApp()
    {
        return dynamic_cast<App*>(qApp);
    }

    // Метод
    // settings() возвращает указатель на объект настроек:
    QSettings* settings()
    {
        return m_pSettings;
    }
};
