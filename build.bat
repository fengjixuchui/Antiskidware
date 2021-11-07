@echo off
title Antiskidware Build

echo Create dist folder.
mkdir dist

echo Building boot binary...
nasm -f bin -o dist/boot.bin boot.asm

echo Building Exe..
g++ main.cpp -o dist/Antiskidware.exe -static-libgcc -static-libstdc++

echo Finished.
pause