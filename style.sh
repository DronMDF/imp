#!/bin/sh

set -ue
set -v

# Check coding style
cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet *.cpp test/*.cpp
cpplint *.cpp *.h test/*.cpp

#uncrustify -c uncrustify.conf --check -q `find 2out/ -name *.cpp -o -name *.h` `find test/ -name *.cpp -o -name *.h`

# Check pdd tokens
pdd > /dev/null
