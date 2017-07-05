@rem modify files.xml and import images automaticlly
@echo off
setlocal enabledelayedexpansion
set date_time=%date:~0,10% %time:~0,8%

@rem get parameters
set replaces=%1
set importImages=%2
set log.txt=%3

@rem step1: change default modality
echo %date_time% : step1- change default modality...>>%log.txt%
set file=D:\\UIH\appdata\user_settings\default\config\service\ServiceSite.xml
@rem set file=D:\\ServiceSite.xml
if not exist %file% (
    echo %date_time% : faild- %file% missing...>>%log.txt%
    goto step2
)
set replaced=PT
set replacing=CT

for /f "delims=" %%i in ('type "%file%"') do (
	set str=%%i
	set "str=!str:%replaced%=%replacing%!"
	echo !str!>>%file%_tmp.txt
)
copy "%file%" "%file%"_bak >nul 2>nul
@rem move "%file%"_tmp.txt "%file%"
echo %date_time% : sucessed- %file% current modality is %replacing%...>>%log.txt%

@rem step2: import images to database
:step2
echo --------------------------------------------------------------------->>%log.txt%
echo %date_time% : step2- importer images to database...>>%log.txt%
set importer=D:\\UIH\bin\McsfDicomDBImporterTool.exe
if not exist %importer% (
    echo %date_time% : faild- %importer% missing...>>%log.txt%
    goto step3
)

set images="E:\\dicom data\Vessel137"
%importer% %images%

@rem todo by yourself
:step3
echo --------------------------------------------------------------------->>%log.txt%
