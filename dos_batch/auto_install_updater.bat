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
for /f "delims=" %%i in ('xml sel -t -v "//InstallVersion" %configFile%') do ( set local_verion=%%i)
for /f "delims=" %%i in ('xml sel -t -v "//InstallVersion" %auto_install_server%%configFile%') do ( set server_verion=%%i)

if not "%local_verion%" equ "%server_verion%" (
    copy /Y %auto_install_server%auto_install.bat .\
    copy /Y %auto_install_server%auto_install_after.bat .\
    copy /Y %auto_install_server%auto_install_schtasks* .\
    
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

