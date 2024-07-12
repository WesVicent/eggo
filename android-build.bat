@ECHO OFF

SET buildpath=%~dp0out\build\Android\

CALL git clone --recurse-submodules --remote-submodules -j8 https://github.com/WesVicent/template-android-ndk-build.git %buildpath%

RMDIR /Q/S %buildpath%\.git

ECHO Android build created at %buildpath%.