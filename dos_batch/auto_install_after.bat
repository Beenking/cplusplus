@echo on
setlocal enabledelayedexpansion
set log.txt=C:\\auto_install_after_log.txt
set log_error.txt=C:\\auto_install_after_error.txt
set date_time=%date:~0,10%%time:~0,8%

@rem step1: change default modality
echo %date_time% : step1- change default modality...>>%log.txt%
set file=D:\\UIH\appdata\review\website.xml
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
move "%file%"_tmp.txt "%file%"
echo %date_time% : sucessed- %file% current modality is %replacing%...>>%log.txt%

@rem step2: import images to database
:step2
echo --------------------------------------------------------------------->>%log.txt%
echo %date_time% : step2- importer images to database...>>%log.txt%
set importer=D:\\UIH\bin\importer.exe
set images=E:\\image
if not exist %importer% (
    echo %date_time% : faild- %file% missing...>>%log.txt%
    goto step3
)
%importer% images

@rem todo by yourself
:step3
echo --------------------------------------------------------------------->>%log.txt%