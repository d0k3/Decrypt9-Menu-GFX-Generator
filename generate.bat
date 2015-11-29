@echo off

rm exec.bat
rm -r build
rm -r output

make

call D9mGFXgen > exec.bat
call exec.bat

pause