@echo off
cls

set CC=gcc
set CFLAGS=-Wall -Wextra -std=c99
set TARGET=temperature_stat

echo Compiling...
%CC% %CFLAGS% main.c Temp_function.c -o %TARGET%

if errorlevel 1 (
    echo Compilation failed!
) else (
    echo Compilation successful!
    echo Executable file: %TARGET%.exe
)
