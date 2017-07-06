@rem install zhenghe or uideal system from remote automaticlly
@echo off
setlocal enabledelayedexpansion
set date_time=%date:~0,10% %time:~0,8%
set xmlexe=D:\\UIHPM\auto_install\xml.exe
if not exist "%xmlexe%" (
    echo %date_time% : %xmlexe% not found>>auto_error.txt
    goto failed
)
set autoInstallConfig=D:\\UIHPM\auto_install\auto_install_config.xml
if not exist "%autoInstallConfig%" (
    echo %date_time% : %xmlexe% not found>>auto_error.txt
    goto failed
)

@rem get parameters from config.xml by xml.exe
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//RemotePackagePath" %autoInstallConfig%') do ( set uideal_package_output_remote=%%i)
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//MappingLocalDriver" %autoInstallConfig%') do ( set driver=%%i)
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//IgnoreFailedPackage" %autoInstallConfig%') do ( set ignoreFailed=%%i)
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//InstallLog" %autoInstallConfig%') do ( set log.txt=%%i)
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//InstallError" %autoInstallConfig%') do ( set log_error.txt=%%i)

@rem exit if remote path not found
if not exist %uideal_package_output_remote% (
    echo %date_time% : remote path %uideal_package_output_remote% not found, please check network>>%log_error.txt%
    goto failed
)

@rem today_year_month_day format example: 20170629
reg add "HKEY_CURRENT_USER\Control Panel\International" /v sShortDate /t REG_SZ /d yyyy/MM/dd /f>nul
set today_year_month_day=%date:~0,10%
set today_year_month_day=%today_year_month_day:/=%
echo installing file contains : %today_year_month_day%

@rem today_year_month format example: 2017-06
set today_year_month=%date:~0,7%
set today_year_month=%today_year_month:/=-%
echo installing file in directory : %today_year_month%

@rem network mapping to local driver
net use %driver% /d /y
net use %driver%  %uideal_package_output_remote%

@rem cd directory of uideal output
%driver%
cd %today_year_month%

@rem get latest install package
@rem %driver%\%today_year_month%\
set install_package=empty
for %%i in (*%today_year_month_day%*.exe) do (
    if %%i GTR !install_package! (
        set install_package=%%i
    )
)

@rem exit if no package on today
if "%install_package%"=="empty" (
    echo %date_time% : package to be installed on %date:~0,10% not found>>%log_error.txt%
    goto failed
)

@rem set package pull path
set uideal_package_output_remote_package_file=%uideal_package_output_remote%\%today_year_month%\%install_package%
echo.>>%log.txt%
echo %date_time% : installing remote package path is %uideal_package_output_remote_package_file%>>%log.txt%

@rem install package use UIHPM.bat
D:
cd D:\\UIHPM
if exist UIHPM.bat (
    echo %date_time% : starting install package...
    echo %date_time% : starting install package...>>%log.txt%
    echo.>>%log.txt%
    echo ...................................UIHPM LOG START...............................>>%log.txt%
    UIHPM i dev %uideal_package_output_remote_package_file%>>%log.txt%
    echo ...................................UIHPM LOG END.................................>>%log.txt%
    echo.>>%log.txt%
    echo %date_time% : %install_package% install succssed>>%log.txt%
    echo --------------------------------------------------------------------------->>%log.txt%
    net use %driver% /d /y
    exit
    
) else (
    echo %date_time% : D:\\UIHPM\UIHPM.bat is missing
    echo %date_time% : D:\\UIHPM\UIHPM.bat is missing>>%log_error.txt%
	goto failed
)

@rem exception handler
:failed
echo --------------------------------------------------------------------------->>%log_error.txt%
net use %driver% /d /y
exit

