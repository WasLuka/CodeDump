@echo off
set /p name="What is your name?"
if %name%==luka (goto a) else (goto b)

:b
echo this is not Luka this is %name%
pause
exit

:a
echo hi Luka
pause
