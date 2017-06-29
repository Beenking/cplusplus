@rem install application
@echo on
@REM %~d0
@REM cd %~p0

@rem today_year_month_day format example: 20170629
set today_year_month_day=%date:~0,10%
set today_year_month_day=%today_year_month_day:/=%
echo %today_year_month_day%

@rem today_year_month format example: 2017-06
set today_year_month=%date:~0,7%
set today_year_month=%today_year_month:/=-%
echo %today_year_month%

@rem UIDeal_Output path
@rem net use z //10.6.5.4/...
::instead of rem 
D:
set uideal_package_output=D://FF/
set uideal_package_output_date=%uideal_package_output%%today_year_month%
cd %uideal_package_output_date%

for %%i in (%uideal_package_output_date%/*) do (
	set var=%(%%i:%today_year_month_day%=)%
	if "var"=="%%i" set install_package=%%i
)
echo %install_package%

pause