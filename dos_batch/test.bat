@echo off
setlocal enabledelayedexpansion
%~d0
cd %~p0

for /f "delims=" %%n in ('xml sel -t -v "count(/AutoInstall/AfterInstall/ReplaceGroup/Replace)" auto_install_config.xml') do set ReplaceNum=%%n
for /L %%i in (1,1,%ReplaceNum%) do (
    for /f "delims=" %%u in ('xml sel -t -v "//File[%%i]" auto_install_config.xml') do set file=%%u
    for /f "delims=" %%v in ('xml sel -t -v "//XmlLocation[%%i]" auto_install_config.xml') do set location=%%v
    for /f "delims=" %%w in ('xml sel -t -v "//Dst[%%i]" auto_install_config.xml') do set dst=%%w
    echo !file!  !location!  !dst!
    if exist "!file!" ( 
        copy "!file!" "!file!_bak" >nul 2>nul
        type "!file!_bak" | xml ed -u "!location!" -v !dst! "!file!_bak">!file!
    )
)

pause