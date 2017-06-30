SCHTASKS /Delete /TN UIHAutoInstall /F
SCHTASKS /Create /TN UIHAutoInstall /XML install_auto.xml