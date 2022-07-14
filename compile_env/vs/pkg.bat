@echo off

set curr_dir=%~dp0
set top_dir=%curr_dir%..\..
echo [easy_tools]:"top_dir=%top_dir%"
set Debug_Release=%1
echo [easy_tools]:"Debug_Release=%Debug_Release%"
set Win32_x64=%2
echo [easy_tools]:"Win32_x64=%Win32_x64%"
set out_dir=%top_dir%\output
echo [easy_tools]:"out_dir=%out_dir%"

set inc_dir=%out_dir%\include
set lib_dir=%out_dir%\lib
set lib_dir_x86=%lib_dir%\x86
set lib_dir_x64=%lib_dir%\x64

if not exist %out_dir% mkdir %out_dir%
if not exist %inc_dir% mkdir %inc_dir%
if not exist %lib_dir_x64% mkdir %lib_dir_x64%
if not exist %lib_dir_x86% mkdir %lib_dir_x86%

echo [easy_tools]:"¿½±´½Ó¿ÚÎÄµµ.md"
xcopy>nul %top_dir%\docs\½Ó¿ÚÎÄµµ.md %out_dir%\ /F /Y 

echo [easy_tools]:"¿½±´include"
xcopy>nul %top_dir%\src\*.h %inc_dir%\ /F /Y /E

if "%Debug_Release%"=="Debug" (
	echo [easy_tools]:"¿½±´libet-d.dll"
	if "%Win32_x64%"=="Win32" (
		xcopy>nul %top_dir%\bin\libet-d.dll %out_dir%\lib\x86 /F /Y	
		xcopy>nul %top_dir%\bin\libet-d.lib %out_dir%\lib\x86 /F /Y	
	) 
	
	if "%Win32_x64%"=="x64" (
		xcopy>nul %top_dir%\bin\libet-d.dll %out_dir%\lib\x64 /F /Y	
		xcopy>nul %top_dir%\bin\libet-d.lib %out_dir%\lib\x64 /F /Y	
	) 
)

if "%Debug_Release%"=="Release" (
	echo [easy_tools]:"¿½±´libet-r.dll"
	if "%Win32_x64%"=="Win32" (
		xcopy>nul %top_dir%\bin\libet-r.dll %out_dir%\lib\x86 /F /Y	
		xcopy>nul %top_dir%\bin\libet-r.lib %out_dir%\lib\x86 /F /Y	
	) 
	
	if "%Win32_x64%"=="x64" (
		xcopy>nul %top_dir%\bin\libet-r.dll %out_dir%\lib\x64 /F /Y	
		xcopy>nul %top_dir%\bin\libet-r.lib %out_dir%\lib\x64 /F /Y	
	) 
)