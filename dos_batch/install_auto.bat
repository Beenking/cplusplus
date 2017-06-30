@rem install zhenghe or uideal system from remote automaticlly
@echo off
set driver=X:
set uideal_package_output_remote=\\10.6.4.5\SW_Publish\UIDeal_BuildOutput
set date_time=%date:~0,10% %time:~0,8%

if not exist %uideal_package_output_remote% (
	echo %date_time% : remote package cannt use
	echo %date_time% : remote package cannt use>>C:\\install_auto_error.txt
	exit
)

@rem today_year_month_day format example: 20170629
set today_year_month_day=%date:~0,10%
set today_year_month_day=%today_year_month_day:/=%
echo installing file contains : %today_year_month_day%

@rem today_year_month format example: 2017-06
set today_year_month=%date:~0,7%
set today_year_month=%today_year_month:/=-%
echo installing file in directory : %today_year_month%

@rem network mapping
net use %driver% /d /y
net use %driver%  %uideal_package_output_remote%

@rem cd directory of uideal output
%driver%
cd %today_year_month%

@rem %driver%\%today_year_month%\
for %%i in (*%today_year_month_day%*.exe) do (
	set install_package=%%i
	echo installing package file is %%i
)
set uideal_package_output_remote_package_file=%uideal_package_output_remote%\%today_year_month%\%install_package%
echo installing package remote name is %uideal_package_output_remote_package_file%

%~d0
cd %~p0
@rem install package use UIHPM.bat
if exist ./UIHPM.bat (
	echo starting install package...
	UIHPM i dev %uideal_package_output_remote_package_file%
	echo install package successed.
	echo %date_time% : %install_package% install succssed>>C:\\install_auto_log.txt.
) else (
	echo %date_time% : UIHPM.bat is missing
	echo %date_time% : UIHPM.bat is missing>>C:\\install_auto_error.txt
)

net use %driver% /d /y