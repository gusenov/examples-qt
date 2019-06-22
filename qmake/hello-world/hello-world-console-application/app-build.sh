#!/bin/bash

app_name="$(basename `pwd`)"
build_dir_name="build-$app_name"

version="5.12.4"
qmake_exe="$HOME/Qt${version}/${version}/clang_64/bin/qmake"

$qmake_exe -v
# QMake version 3.1
# Using Qt version 5.12.4 in ~/Qt5.12.4/5.12.4/clang_64/lib

rm *.pro
# Создать qmake файл, по сути проектный .pro файл:
$qmake_exe -project

cd ..
[ -d "$build_dir_name" ] && rm -rf "$build_dir_name"
mkdir "$build_dir_name"
cd "$build_dir_name"

# Создать "Makefile" с правилами построения приложения:
rm .qmake.stash
rm Makefile
$qmake_exe "../$app_name/$app_name.pro"

# Построить приложение в соответствии с "Makefile":
rm -rf *.app
/usr/bin/make

"./$app_name.app/Contents/MacOS/$app_name"
