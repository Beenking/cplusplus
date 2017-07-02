SCHTASKS /Delete /TN UIHAutoInstall /F
SCHTASKS /Delete /TN UIHAutoInstallAfter /F
SCHTASKS /Create /RU %USERNAME% /RP /TN UIHAutoInstall /XML auto_install.xml
SCHTASKS /Create /RU %USERNAME% /RP /TN UIHAutoInstallAfter /XML auto_install_after.xml

pause