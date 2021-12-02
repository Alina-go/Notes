Set dir=C:\Notes\CoverageReport

Echo Deleting all files from %dir%
del %dir%\* /F /Q

Echo Deleting all folders from %dir%
for /d %%p in (%dir%\*) Do rd /Q /S "%%p"
echo Folder deleted.

del /q /s fileName.xml 
del /q /s LastCoverageResults.log
