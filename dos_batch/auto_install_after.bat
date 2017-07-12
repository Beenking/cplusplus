@rem modify files.xml and import images automaticlly
@echo off
setlocal enabledelayedexpansion
set date_time=%date:~0,10% %time:~0,8%
set server_log_path=\\10.6.2.12\public\VT_WB\auto_install_log

%~d0
cd %~p0
set xmlexe=xml.exe
if not exist "%xmlexe%" (
    echo %date_time% : %xmlexe% not found>>auto_error.txt
    exit
)
set configFile=auto_install_config.xml
if not exist "%configFile%" (
    echo %date_time% : %xmlexe% not found>>auto_error.txt
    exit
)

@rem get parameters from config.xml by xml.exe
for /f "delims=" %%i in ('xml sel -t -v "//AfterLog " %configFile%') do ( set log.txt=%%i)
for /f "delims=" %%i in ('xml sel -t -v "//DeleteOldest" %configFile%') do ( set autoDel=%%i)
for /f "delims=" %%i in ('xml sel -t -v "//DBImporter/@exe" %configFile%') do ( set importer=%%i)
if exist "%log.txt%" del %log.txt%

@rem step1: change default file.xml value
:step1
echo %date_time% : step1- change default xml file...>>%log.txt%
for /f "delims=" %%n in ('xml sel -t -v "count(/AutoInstall/AfterInstall/ReplaceGroup/Replace)" %configFile%') do set ReplaceNum=%%n
for /L %%i in (1,1,%ReplaceNum%) do (
    for /f "delims=" %%u in ('xml sel -t -v "//File[%%i]" %configFile%') do set file=%%u
    for /f "delims=" %%v in ('xml sel -t -v "//XmlLocation[%%i]" %configFile%') do set location=%%v
    for /f "delims=" %%w in ('xml sel -t -v "//Value[%%i]" %configFile%') do set value=%%w
    if exist "!file!" ( 
        copy "!file!" "!file!_bak" >nul 2>nul
        xml ed -u "!location!" -v !value! "!file!_bak">!file!
        echo %date_time% : successed change- !file! !location! !value! >>%log.txt%
    ) else (
        echo %date_time% : faild changed- !file! is missing...>>%log.txt%
    )
)

@rem step2: import images to database
:step2
echo --------------------------------------------------------------------->>%log.txt%
echo %date_time% : step2- importer images to database...>>%log.txt%
chcp 65001
if not exist "%importer%" (
    echo %date_time% : faild- %importer% missing...>>%log.txt%
    goto step3
)
for /f "delims=" %%i in ('xml sel -t -v "//DicomImages" %configFile%') do (
    if exist "%%i" (
       %importer% "%%i"
       echo %date_time% : successed importer- %importer% "%%i">>%log.txt%
   ) else (
       echo %date_time% : faild importer- "%%i" missing...>>%log.txt%
   )
)

@rem step3: auto delete oldest package
:step3
echo --------------------------------------------------------------------->>%log.txt%
echo %date_time% : todo step3- auto delete oldest package...>>%log.txt%
D:
cd D:\\UIHPM
if /i "%autoDel%"=="true" (
    for /f "tokens=1,2,3 delims= " %%i in ('UIHPM L') do (
        echo %%i---%%j---%%k
        for /f "tokens=1 delims=." %%x in ("%%k") do (
            echo %%x
        )
    )
)




@rem step4: todo by yourself
:step4
echo --------------------------------------------------------------------->>%log.txt%


@rem today_year_month_day format example: 20170629
reg add "HKEY_CURRENT_USER\Control Panel\International" /v sShortDate /t REG_SZ /d yyyy/MM/dd /f>nul
set today_year_month_day=%date:~0,10%
set today_year_month_day=%today_year_month_day:/=%
set current_time=%time:~0,11%
set current_time=%current_time::=%
set current_time=%current_time:.=%
set current_time=%current_time: =%
mkdir %server_log_path%\%today_year_month_day%\%USERNAME%\
copy /Y %log.txt% %server_log_path%\%today_year_month_day%\%USERNAME%\auto_install_after_log_%current_time%.txt
