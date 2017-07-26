rem ------------------------------------------------------------
rem Set temporary environment variables
rem ------------------------------------------------------------

rem ��Need to change��
set ProjectName=ProteusModbus�ӻ�
set BakDirName=2.%ProjectName%
set BakDirPath=..\..\..\3.Working-Copy\10.ProteusModbus\%BakDirName%\%DATE:~0,10%
set CleanDir1=Output

rem ��No need to change��
set BakRarFile=.\%ProjectName%.rar

rem ------------------------------------------------------------
rem Del the last backup file & Obj files
rem ------------------------------------------------------------

rem ��Need to change��
del /q .\%CleanDir1%\*.*

rem ��No need to change��
del /q %BakRarFile%

rem ------------------------------------------------------------
rem Zip all files to be a "rar" file
rem ------------------------------------------------------------

rem ��No need to change��
WinRAR a -r %BakRarFile% .

rem ------------------------------------------------------------
rem Create the backup folder
rem ------------------------------------------------------------

rem ��No need to change��
md %BakDirPath%

rem ------------------------------------------------------------
rem Copy the rar file to the backup folder
rem ------------------------------------------------------------

rem ��No need to change��
copy %BakRarFile% %BakDirPath%

rem ------------------------------------------------------------
rem Clean the temporary environment variables
rem ------------------------------------------------------------

rem ��Need to change��
set CleanDir1=

rem ��No need to change��
set ProjectName=
set BakDirName=
set BakDirPath=
set BakRarFile=

rem ------------------------------------------------------------
rem Waiting user to confirm everything is OK
rem ------------------------------------------------------------

rem ��No need to change��
pause