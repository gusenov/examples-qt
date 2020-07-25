#!/usr/bin/env bash

qmllivebench="$HOME/repo/qmllive/bin/qmllivebench"
path_to_workspace="$(pwd)"

for i in "$@"; do
case $i in
    -w=*|--workspace=*)
    path_to_workspace="${i#*=}"
    shift # past argument=value
    ;;
esac
done




# Подключение из QML Live Bench:

# Добавить host в QML Live Bench:
"$qmllivebench" --addhost myapp,localhost,10234

# Запустить QML Live:
"$qmllivebench" "$path_to_workspace"  # The SRCDIR of the example project.

"$qmllivebench" --rmhost myapp
