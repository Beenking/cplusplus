SCHTASKS /Delete /TN UIHAutoInstall /F
SCHTASKS /Delete /TN UIHAutoInstallAfter /F
SCHTASKS /Create /TN UIHAutoInstall /XML auto_install.xml
SCHTASKS /Create /TN UIHAutoInstallAfter /XML auto_install_after.xml

pause