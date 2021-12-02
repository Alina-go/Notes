set QTDIR=C:\Qt\5.15.1\msvc2019_64
set PATH=C:\Program Files (x86)\Python37-32\Lib;C:\Qt\5.15.1\msvc2019_64\bin;C:\Program Files\Git\usr\bin;\\VBOXSVR\Libraries\third2019\openssl\bin;%PATH%
echo vcvarsall
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" amd64


rmdir /s /q C:\actions-runner\_work\Notes\Build
mkdir C:\actions-runner\_work\Notes\Build
cd C:\actions-runner\_work\Notes\Build
           
qmake C:\actions-runner\_work\Notes\Notes\NotesAndTests.pro      

echo Build debug and release exes
nmake debug
nmake release