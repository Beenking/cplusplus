@rem install zhenghe or uideal system from remote automaticlly
@echo off
set driver=X:
set log.txt=C:\\auto_install_log.txt
set log_error.txt=C:\\auto_install_error.txt
set uideal_package_output_remote=\\127.0.0.1\SharedDir
set date_time=%date:~0,10% %time:~0,8%

@rem exit if remote path not found
if not exist %uideal_package_output_remote% (
    echo %date_time% : remote path %uideal_package_output_remote% not found, please check network>>%log_error.txt%
    goto failed
)

@rem today_year_month_day format example: 20170629
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

@rem %driver%\%today_year_month%\
set install_package=empty
for %%i in (*%today_year_month_day%*.exe) do (
    set install_package=%%i
    echo installing package file is %%i
)

@rem exit if no package on today
if "%install_package%"=="empty" (
    echo %date_time% : package to be installed on %date:~0,10% not found>>%log_error.txt%
    goto failed
)

@rem set package pull path
set uideal_package_output_remote_package_file=%uideal_package_output_remote%\%today_year_month%\%install_package%
echo %date_time% : installing remote package path is %uideal_package_output_remote_package_file%>>%log.txt%

%~d0
cd %~p0
@rem install package use UIHPM.bat
if exist ./UIHPM.bat (
    echo %date_time% : starting install package...>>%log.txt%
    UIHPM i dev %uideal_package_output_remote_package_file%
    echo install package successed.
    echo %date_time% : %install_package% install succssed>>%log.txt%
    goto successed
    
) else (
    echo %date_time% : UIHPM.bat is missing
    echo %date_time% : UIHPM.bat is missing>>%log_error.txt%
	goto failed
)

:failed
echo --------------------------------------------------------------------------->>%log_error.txt%
net use %driver% /d /y
exit
:successed
echo --------------------------------------------------------------------------->>%log.txt%
net use %driver% /d /y
exit
