rem echo off
mkdir ..\..\..\mame_build_vs12
pushd ..\..\..\mame_build_vs12

cmake -G"Visual Studio 12 2013" ..\nitro\native\emulator

call "%VS120COMNTOOLS%vsvars32.bat"
MSBuild devmame.sln /maxcpucount /p:Configuration=Release

REM copy Release\nitro.exe ..\..\nitro\bin

popd

