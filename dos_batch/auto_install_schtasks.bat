@echo off

@rem todo get paras from config.xml
set RemotePackage=\\10.6.4.5\SW_Publish\UIDeal_BuildOutput
set MappingLocalDriver=X:
set IgnoreFailedPackage=True
set InstallLog=C:\\auto_install_log.txt
set InstallError=C:\\auto_install_error.txt

set Replaces="path1 src dst,path2 src2 dst2"
set ImportImages="image1,image2,image3"
set AfterLog=C:\\auto_install_log.txt

set /p password=please input password of %USERNAME%:
SCHTASKS /Delete /TN UIHAutoInstall /F
SCHTASKS /Create /RU %USERNAME% /RP %password% /TN UIHAutoInstall /XML auto_install.xml
SCHTASKS /Change /RU %USERNAME% /RP %password% /TN UIHAutoInstall /TR "D:\UIHPM\auto_install.bat %RemotePackage% %MappingLocalDriver% %IgnoreFailedPackage% %InstallLog% %InstallError%"
@rem SCHTASKS /Delete /TN UIHAutoInstallAfter /F
@rem SCHTASKS /Create /RU %USERNAME% /RP %password% /TN UIHAutoInstallAfter /XML auto_install_after.xml
@rem SCHTASKS /Change /RU %USERNAME% /RP %password% /TN UIHAutoInstallAfter /TR "D:\UIHPM\auto_install_after.bat %Replaces% %ImportImages% %AfterLog%"

pause