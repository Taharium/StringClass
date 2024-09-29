@echo off
mkdir wslClangBuild
pushd wslClangBuild
wsl clang++ -std=c++17 ../main.cpp ../src/String.cpp -o main
popd
wsl wslClangBuild/main
pause