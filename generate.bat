@echo off

make clean
make

call D9mGFXgen > exec.bat
call exec.bat
md output
move base??.png output/
move menu????.png output/

pause