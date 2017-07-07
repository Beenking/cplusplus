@rem modify files.xml and import images automaticlly
@echo off
setlocal enabledelayedexpansion
set date_time=%date:~0,10% %time:~0,8%
%~d0
cd %~p0
set xmlexe=xml.exe
if not exist "%xmlexe%" (
    echo %date_time% : %xmlexe% not found>>auto_error.txt
    goto failed
)
set configFile=auto_install_config.xml
if not exist "%configFile%" (
    echo %date_time% : %xmlexe% not found>>auto_error.txt
    goto failed
)

@rem get parameters from config.xml by xml.exe
set ImportImages=
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//DicomImages" %configFile%') do (
    if defined ImportImages (
        set ImportImages=!ImportImages!;%%i
    ) else (
        set ImportImages=%%i
    )
)
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//AfterLog " %configFile%') do ( set log.txt=%%i)
for /f "delims=" %%i in ('%xmlexe% sel -t -v "//AutoDeleteLast" %configFile%') do ( set autoDel=%%i)

@rem step1: change default file.xml value
:step1
echo %date_time% : step1- change default xml file...>>%log.txt%
for /f "delims=" %%n in ('xml sel -t -v "count(/AutoInstall/AfterInstall/ReplaceGroup/Replace)" %configFile%') do set ReplaceNum=%%n
for /L %%i in (1,1,%ReplaceNum%) do (
    for /f "delims=" %%u in ('xml sel -t -v "//File[%%i]" %configFile%') do set file=%%u
    for /f "delims=" %%v in ('xml sel -t -v "//XmlLocation[%%i]" %configFile%') do set location=%%v
    for /f "delims=" %%w in ('xml sel -t -v "//Dst[%%i]" %configFile%') do set dst=%%w
    if exist "!file!" ( 
        copy "!file!" "!file!_bak" >nul 2>nul
        type "!file!_bak" | xml ed -u "!location!" -v !dst! "!file!_bak">!file!
        echo %date_time% : successed change- !file! !location! !dst! >>%log.txt%
    ) else (
        echo %date_time% : faild changed- !file! is missing...>>%log.txt%
    )
)

@rem step2: import images to database
:step2
echo --------------------------------------------------------------------->>%log.txt%
echo %date_time% : step2- importer images to database...>>%log.txt%
set importer=D:\\UIH\bin\McsfDicomDBImporterTool.exe
if not exist %importer% (
    echo %date_time% : faild- %importer% missing...>>%log.txt%
    goto step3
)

@rem set importImages=%importImages:"=%
set t=%importImages%
:loop
for /f "tokens=1* delims=;" %%a in ("%t%") do (
   if exist "%%a" (
       %importer% "%%a"
       echo %date_time% : successed importer- %importer% "%%a">>%log.txt%
   ) else (
       echo %date_time% : faild importer- "%%a" missing...>>%log.txt%
   )  
   set t=%%b
)
if defined t goto :loop


@rem todo by yourself
:step3
echo --------------------------------------------------------------------->>%log.txt%




