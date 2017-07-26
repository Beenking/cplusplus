@rem echo off 

setlocal enabledelayedexpansion
set auto_install_server=\\10.6.2.12\public\auto_install\
set configFile=auto_install_config.xml
if not exist %configFile% (
    copy /Y %auto_install_server%* .\
)

if not exist xml.exe (
    copy /Y %auto_install_server%xml.exe .\
)

@rem get parameters from config.xml by xml.exe
for /f "delims=" %%i in ('xml sel -t -v "//InstallVersion" %configFile%') do ( set local_version=%%i)
for /f "delims=" %%i in ('xml sel -t -v "//InstallVersion" %auto_install_server%%configFile%') do ( set server_version=%%i)
for /f "delims=" %%i in ('xml sel -t -v "//InstallLog" %configFile%') do ( set log.txt=%%i)

if not "%local_version%" equ "%server_version%" (
    echo auto_install local verison:%local_version% not equ server version %server_version%>>%log.txt%
    echo updater all bat files to current directory>>%log.txt%
    
    @rem modify local config xml version
    xml ed -u "//InstallVersion" -v "%server_version%" "%configFile%">>"%configFile%_temp"
    del /f "%configFile%"
    ren %configFile%_temp %configFile%

    copy /Y %auto_install_server%auto_install.bat .\
    copy /Y %auto_install_server%auto_install_after.bat .\
    copy /Y %auto_install_server%auto_install_schtasks* .\
    
    @rem todo:add elment for xml
    for /f "delims=" %%i in ('xml el -u %configFile%') do ( set local_xml_element=!local_xml_element!;%%i)
    echo !local_xml_element!
    for /f "delims=" %%i in ('xml el -u %auto_install_server%%configFile%') do ( 
        echo !local_xml_element! | find "%%i"
        if !errorlevel!==1 (
            set addXpath=%%i
        )
    )  
    echo !addXpath!
    for /f "delims=/" %%j in ("!addXpath!") do (
        echo %%j
        pause
    )
    @rem copy /Y %auto_install_server%auto_install_updater.bat .\
)

