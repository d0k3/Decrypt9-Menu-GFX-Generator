@ECHO OFF
SETLOCAL EnableDelayedExpansion
COLOR 0A

IF NOT EXIST "UI" (
	ECHO.
	ECHO ======================================
	ECHO.
	ECHO     UI Folder does not exist...
	ECHO.
	ECHO     Creating UI Folder...
	ECHO.
	mkdir "UI" >NUL
	GOTO:CONVERT
) ELSE IF EXIST "UI" (
	ECHO ======================================
	ECHO.
	ECHO     UI Folder already exists...
	ECHO.    No need to create it...
	ECHO.
	GOTO:CONVERT
)

:CONVERT
TITLE Working...
ECHO ======================================
ECHO.
ECHO     Converting Output png's to bin...
ECHO.
ECHO     Please Wait...
ECHO.
ECHO ======================================
ECHO.

FOR %%1 IN ("output\menu????.png") DO (
	(SET /P j="|") < NUL
	convert "%%1" -rotate 90 "%%~n1.bgr"
	sleep 0.1
	REN "%%~n1.bgr" "%%~n1.bin"
	sleep 0.1
)
GOTO:MOVE

:MOVE
	MOVE /Y "menu????.bin" "UI" >NUL
	ECHO.
	ECHO.
	ECHO ======================================
	ECHO.
	ECHO     menu bin files moved to UI folder...
	ECHO.
	GOTO:DONE

:DONE
	ECHO ======================================
	ECHO.
	ECHO     DONE!
	ECHO.
	ECHO ======================================
	ECHO.
	TITLE Done...

pause
