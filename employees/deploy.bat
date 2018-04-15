@echo off
cls

setlocal

set qt_dir=C:\Qt\Qt5.10.1\5.10.1\mingw53_32\bin
set exe_dir=C:\Users\user\Documents\build-employees-Desktop_Qt_5_10_1_MinGW_32bit-Debug\debug
set upx_dir=C:\upx

rem call :DeleteDLL "%exe_dir%"
rem call :CopyDLL "%qt_dir%" "%exe_dir%"
rem call :PackDLL "%exe_dir%" "%upx_dir%"

endlocal
EXIT /B %ERRORLEVEL%

:CopyDLL
setlocal

rem  /B           Файл является двоичным файлом.
rem  /V           Проверка правильности копирования файлов.
rem  /Y           Подавление запроса подтверждения на перезапись существующего
rem               конечного файла.

copy "%~1\libwinpthread-1.dll" "%~2\" /B /V /Y
copy "%~1\libgcc_s_dw2-1.dll" "%~2\" /B /V /Y
copy "%~1\libstdc++-6.dll" "%~2\" /B /V /Y
copy "%~1\Qt5Core.dll" "%~2\" /B /V /Y
copy "%~1\Qt5Widgets.dll" "%~2\" /B /V /Y
copy "%~1\Qt5Gui.dll" "%~2\" /B /V /Y
copy "%~1\Qt5Sqld.dll" "%~2\" /B /V /Y
copy "%~1\Qt5Cored.dll" "%~2\" /B /V /Y
copy "%~1\Qt5Widgetsd.dll" "%~2\" /B /V /Y
copy "%~1\Qt5Guid.dll" "%~2\" /B /V /Y

rem libwinpthread-1.dll    77,5 КБ
rem libgcc_s_dw2-1.dll     117  КБ
rem libstdc++-6.dll        1,46 МБ
rem Qt5Core.dll            5,89 МБ
rem Qt5Widgets.dll         5,94 МБ
rem Qt5Gui.dll             6,11 МБ
rem Qt5Sqld.dll            8,31 МБ
rem Qt5Cored.dll           115  МБ
rem Qt5Widgetsd.dll        160  МБ
rem Qt5Guid.dll            215  МБ

endlocal
exit /B 0

:DeleteDLL
setlocal

rem  /F            Принудительное удаление файлов, доступных только для чтения.
rem  /Q            Отключение запроса на подтверждение при удалении файлов.

del "%~1\libwinpthread-1.dll" /F /Q
del "%~1\libgcc_s_dw2-1.dll" /F /Q
del "%~1\libstdc++-6.dll" /F /Q
del "%~1\Qt5Core.dll" /F /Q
del "%~1\Qt5Widgets.dll" /F /Q
del "%~1\Qt5Gui.dll" /F /Q
del "%~1\Qt5Sqld.dll" /F /Q
del "%~1\Qt5Cored.dll" /F /Q
del "%~1\Qt5Widgetsd.dll" /F /Q
del "%~1\Qt5Guid.dll" /F /Q

endlocal
exit /B 0

:PackDLL
setlocal

rem -9    compress better

rem -q     be quiet

"%~2\upx.exe" -9 "%~1\libwinpthread-1.dll"^
 "%~1\libgcc_s_dw2-1.dll"^
 "%~1\libstdc++-6.dll"^
 "%~1\Qt5Core.dll"^
 "%~1\Qt5Widgets.dll"^
 "%~1\Qt5Gui.dll"^
 "%~1\Qt5Sqld.dll"^
 "%~1\Qt5Cored.dll"^
 "%~1\Qt5Widgetsd.dll"^
 "%~1\Qt5Guid.dll"

rem libwinpthread-1.dll    35,0 КБ
rem libgcc_s_dw2-1.dll     48,0 КБ
rem libstdc++-6.dll        625  КБ
rem Qt5Core.dll            2,57 МБ
rem Qt5Widgets.dll         2,44 МБ
rem Qt5Gui.dll             2,31 МБ
rem Qt5Sqld.dll            1,93 МБ
rem Qt5Cored.dll           27,1 МБ
rem Qt5Widgetsd.dll        39,2 МБ
rem Qt5Guid.dll            47,0 МБ

endlocal
exit /B 0
