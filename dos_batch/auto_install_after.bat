@rem modify files.xml and import images automaticlly
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
set ImportImages=
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//DicomImages" %autoInstallConfig%') do (
    if defined ImportImages (
        set ImportImages=!ImportImages!;%%i
    ) else (
        set ImportImages=%%i
    )
)
set ImportImages='%ImportImages%'
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//AfterLog " %autoInstallConfig%') do ( set log.txt=%%i)
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//AutoDeleteLast" %autoInstallConfig%') do ( set autoDel=%%i)

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
@rem echo %date_time% : change xml file by config.xml>>%log.txt%

@rem step2: import images to database
:step2
echo --------------------------------------------------------------------->>%log.txt%
echo %date_time% : step2- importer images to database...>>%log.txt%
set importer=D:\\UIH\bin\McsfDicomDBImporterTool.exe
if not exist %importer% (
    echo %date_time% : faild- %importer% missing...>>%log.txt%
    goto step3
)

@rem set s=E:\\dicom data\Vessel137;E:\\CTImage\test;D:\\pet image
set importImages=%importImages:"=%
set t=%importImages%
:loop
for /f "tokens=1* delims=;" %%a in ("%t%") do (
   if exist "%%a" (
       %importe% "%%a"
       echo %date_time% : successed importer- %importer% "%%a">>%log.txt%
   ) else (
       echo %date_time% : faild importer- %%a missing...>>%log.txt%
   )  
   set t=%%b
)
if defined t goto :loop


@rem todo by yourself
:step3
echo --------------------------------------------------------------------->>%log.txt%




