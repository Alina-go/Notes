set PATH=C:\Program Files\Cppcheck
cd C:\actions-runner\_work\Notes\Notes
cppcheck --enable=all . -iunit-tests/ --suppress=missingInclude --output-file=C:\actions-runner\_work\Notes\CppCheckReport\output-result.txt