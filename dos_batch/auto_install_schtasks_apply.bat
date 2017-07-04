@echo off

@rem todo get paras from config.xml
set autoInstall=D:\\UIHPM\auto_install\auto_install.bat
set RemotePackage=\\10.6.4.5\SW_Publish\UIDeal_BuildOutput
set MappingLocalDriver=X:
set IgnoreFailedPackage=True
set InstallLog=C:\\auto_install_log.txt
set InstallError=C:\\auto_install_error.txt

set autoInstallAfter=D:\\UIHPM\auto_install\auto_install_after.bat
set Replaces='path1 src dst,path2 src2 dst2'
set ImportImages='E:\\dicom data\Vessel137,image1,image2,image3'
set AfterLog='C:\\auto_install_log.txt'

set /p password=please input password of %USERNAME%:
SCHTASKS /Delete /TN UIHAutoInstall /F
SCHTASKS /Create /RU %USERNAME% /RP %password% /TN UIHAutoInstall /XML auto_install.xml
SCHTASKS /Change /RU %USERNAME% /RP %password% /TN UIHAutoInstall /TR "%autoInstall% %RemotePackage% %MappingLocalDriver% %IgnoreFailedPackage% %InstallLog% %InstallError%"
SCHTASKS /Delete /TN UIHAutoInstallAfter /F
SCHTASKS /Create /RU %USERNAME% /RP %password% /TN UIHAutoInstallAfter /XML auto_install_after.xml
SCHTASKS /Change /RU %USERNAME% /RP %password% /TN UIHAutoInstallAfter /TR "%autoInstallAfter% %Replaces% %ImportImages% %AfterLog%"
