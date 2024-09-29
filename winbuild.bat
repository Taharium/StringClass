@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 > nul
mkdir winBuild
pushd winBuild
    cl ../main.cpp ../src/String.cpp /ZI /EHsc /DEBUG
popd
