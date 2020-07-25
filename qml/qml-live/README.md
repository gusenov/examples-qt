# Установка

[installation.sh](installation.sh)

# Концепция 

QML Live Bench (The UI Tool) не запускает C++ код приложения напрямую.
Поэтому нет необходимости переупаковывать C++ код как dynamic linked library.

Нужно запустить LiveNodeEngine внутри приложения и ждать подключения от 
QML Live Bench. Когда LiveNodeEngine получает запрос, то он показывает другой
компонент или обновляет существующий.

# Настройка Import Paths

Все live coding инструменты для QML не могут автоматически обнаруживать
QML import paths. Опции ```--pluginpath <pluginpath>```
```--importpath <importpath>``` используются для передачи import paths через
командную строку.

```
$ ./qmllivebench --help
Usage: ./qmllivebench [options] workspace document
QML Live reloading workbench

Options:
  -h, --help                       Displays this help.
  -v, --version                    Displays version information.
  --pluginpath <pluginpath>        path to QML Live plugins
  --importpath <importpath>        path to QML import path. Can appear multiple
                                   times
  --stayontop                      keep viewer window on top
  --addhost <name,address[,port]>  add or update remote host configuration and
                                   exit
  --rmhost <name>                  remove remote host configuration and exit
  --probehost <name>               suggest host became online and should be
                                   connected (implies --remoteonly)
  --noremote                       do not try to talk to a running bench, do
                                   not listen for remote connections.
  --remoteonly                     talk to a running bench, do nothing if none
                                   is running.
  --ping                           just check if there is a bench running and
                                   accepting remote connections.
  --maxdirwatch <number>           limit the number of directories to watch for
                                   changes
  --project                        loads project document .qmllive containing
                                   workspace path, imports paths, main document
                                   in JSON format

Arguments:
  workspace                        workspace folder to watch. If this points to
                                   a QML document, than the directory is
                                   asssumed to be the workspace and the file the
                                   active document.
  document                         main QML document to load initially.
```

Когда используются QPM-пакеты, import path могут быть очень
длинными, поэтому QML Live предлагает альтернативное решение - проектный файл
*.qmllive*. Его можно создать нажав кнопку “New Project” в UI. Нужно задать:

1. Project name (например, *MyQMLLiveProject*)
2. Workspace Folder для наблюдения за обновлениями отредактированных QML-файлов. Путь указывается относительно расположения проектного файла *.qmllive*.
3. Главный QML-документ для начальной загрузки. Задается относительно Workspace Folder.
4. Import paths относительно расположения project document

*MyQMLLiveProject.qmllive*:

```
{
    "imports": [
        "path/relative/to/project/document/location"
    ],
    "main": "main/document.qml",
    "workspace": "path/relative/to/project/file/location"
}
```

Таким образом можно добавлять import paths модифицируя проектный файл. 
После модификации  нужно снова открыть приложение.

# Подключение из QML Live Bench

1. Добавить host в QML Live Bench: ```qmllivebench --addhost myapp,localhost,10234```
2. Запустить QML Live: ```qmllivebench path_to_workspace # The SRCDIR of the example project.```
3. Нажать кнопку “Follow”.
4. Выбрать файл, который нужно показать.
