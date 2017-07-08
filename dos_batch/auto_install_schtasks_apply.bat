@echo off

%~d0
cd %~p0

if not exist "xml.exe" (
    echo %date_time% : xml.exe not found...
    pause
    exit
)
set autoInstallConfig=auto_install_config.xml
if not exist "%autoInstallConfig%" (
    echo %date_time% : %autoInstallConfig% not found...
    pause
    exit
)

if not exist "auto_install.xml" (
    echo %date_time% : auto_install.xml not found...
    pause
    exit
)

if not exist "auto_install_after.xml" (
    echo %date_time% : auto_install_after.xml not found...
    pause
    exit
)

set namespace="http://schemas.microsoft.com/windows/2004/02/mit/task"
@rem change auto_install.xml <Arguments> tag by auto_install_config.xml <AutoLogOff> tag
for /f "delims=" %%i in ('xml sel -t -v "//AutoLogOff" %autoInstallConfig%') do ( set autoLogOff=%%i)
xml ed -N n=%namespace% -u "//n:Arguments" -v %autoLogOff% "auto_install.xml">auto_install.xml_temp
del /f auto_install.xml
ren auto_install.xml_temp auto_install.xml

@rem change auto_install.xml <Command> tag
set install_bat=auto_install.bat
xml ed -N n=%namespace% -u "//n:Command" -v "%~dp0%install_bat%" "auto_install.xml">auto_install.xml_temp
del /f auto_install.xml
ren auto_install.xml_temp auto_install.xml

@rem change auto_install_after.xml <Command> tag
set after_bat=auto_install_after.bat
xml ed -N n=%namespace% -u "//n:Command" -v "%~dp0%after_bat%" "auto_install_after.xml">auto_install_after.xml_temp
del /f auto_install_after.xml
ren auto_install_after.xml_temp auto_install_after.xml

SCHTASKS /Create /RU %USERNAME% /RP /TN UIHAutoInstall /XML auto_install.xml /F
SCHTASKS /Create /RU %USERNAME% /RP /TN UIHAutoInstallAfter /XML auto_install_after.xml /F

pause




