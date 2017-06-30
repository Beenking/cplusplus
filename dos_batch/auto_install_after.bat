@echo off

@rem change modality
setlocal enabledelayedexpansion
set file=a.xml
set replaced=<Modality>PT</Modality>
set replacing=<Modality>CT</Modality>

for /f "delims=" %%i in ('type "%file%"') do (
	set str=%%i
	set "str=!str:%replaced%=%replacing%!"
	echo !str!>>"%file%"_tmp.txt
)

@rem copy "%file%" "%file%"_bak.txt >nul 2>nul
move "%file%"_tmp.txt "%file%"

@rem import images