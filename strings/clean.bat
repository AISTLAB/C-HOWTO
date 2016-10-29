@echo off & color 0a
cd %1
dir
del /s *.obj *.exe
ping -n 1 127.7>nul