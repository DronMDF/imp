#!/bin/sh

set -ue

# Check coding style
cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet .
cpplint `find -name *.cpp -o -name *.h`

#uncrustify -c uncrustify.conf --check -q `find 2out/ -name *.cpp -o -name *.h` `find test/ -name *.cpp -o -name *.h`

# Check pdd tokens
pdd > /dev/null
