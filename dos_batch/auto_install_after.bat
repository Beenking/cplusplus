@echo on

@rem change modality
setlocal enabledelayedexpansion
set file=a.xml
if not exist %file% (
	echo %file% missing...
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