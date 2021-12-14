set path=%path%;C:\msys64\mingw64\bin;C:\msys64\usr\bin
reg.exe ADD "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v Path /t REG_EXPAND_SZ /d "%path%" /f
