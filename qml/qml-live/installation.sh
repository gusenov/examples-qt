#!/usr/bin/env bash

git clone --depth=1 git://code.qt.io/qt-apps/qmllive.git
cd qmllive
$HOME/Qt5.13.0/5.13.0/clang_64/bin/qmake
