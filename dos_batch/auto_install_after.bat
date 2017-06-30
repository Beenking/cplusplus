@echo on
setlocal enabledelayedexpansion
set date_time=%date:~0,10% %time:~0,8%

@rem change modality
set file=a.xml
if not exist %file% (
	echo %date_time% : %file% missing...>>C:\\auto_install_after_error.txt
	pause
	goto import
)

set replaced=PT
set replacing=CT

for /f "delims=" %%i in ('type "%file%"') do (
	set str=%%i
	set "str=!str:%replaced%=%replacing%!"
	echo !str!>>%file%_tmp.txt
)

@rem copy "%file%" "%file%"_bak.txt >nul 2>nul
move "%file%"_tmp.txt "%file%"

pause
@rem import images
:import
echo hello import
pause