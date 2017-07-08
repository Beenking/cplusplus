@echo on
@rem read config.xml file
%~d0
cd %~p0
set xmlexe=xml.exe
if not exist "%xmlexe%" (
    echo %date_time% : %xmlexe% not found>>auto_error.txt
    pause
	exit
)
set autoInstallConfig=auto_install_config.xml
if not exist "%autoInstallConfig%" (
    echo %date_time% : %xmlexe% not found>>auto_error.txt
    pause
	exit
)

@rem get parameters from config.xml by xml.exe
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//AutoLogOff" %autoInstallConfig%') do ( set autoLogOff=%%i)
@rem xml ed -u "//Arguments" -v %autoLogOff% "auto_install.xml"> auto_install.xml

SCHTASKS /Create /RU %USERNAME% /RP /TN UIHAutoInstall /XML auto_install.xml /F
SCHTASKS /Create /RU %USERNAME% /RP /TN UIHAutoInstallAfter /XML auto_install_after.xml /F
