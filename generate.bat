@echo off

make clean
make

call D9mGFXgen > exec.bat
call exec.bat

pause