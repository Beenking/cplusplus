echo off
@rem set /p password=please input password of %USERNAME%:

SCHTASKS /Delete /TN UIHAutoInstall /F
SCHTASKS /Create /RU %USERNAME% /RP /TN UIHAutoInstall /XML auto_install.xml
@rem SCHTASKS /Change /RU %USERNAME% /RP %password% /TN UIHAutoInstall /TR "%autoInstall% %RemotePackage% %MappingLocalDriver% %IgnoreFailedPackage% %InstallLog% %InstallError% %UihpmLog%"

SCHTASKS /Delete /TN UIHAutoInstallAfter /F
SCHTASKS /Create /RU %USERNAME% /RP /TN UIHAutoInstallAfter /XML auto_install_after.xml
@rem SCHTASKS /Change /RU %USERNAME% /RP %password% /TN UIHAutoInstallAfter /TR "%autoInstallAfter% %Replaces% %ImportImages% %AfterLog%"
