#!/bin/sh

cd build
lcov --directory . --zerocounters
cmake ..
cmake --build . --config Debug

./QtTcpSocket

# Create lcov report capturing coverage info
lcov --directory . --capture --output-file coverage.info
# filter out system and extra files.
# To also not include test code in coverage add them with full path to the patterns: '*/tests/*'
lcov --remove coverage.info '/usr/*' "*/*_autogen/*" "${HOME}"'/.cache/*' --output-file coverage.info
# output coverage data for debugging (optional)
lcov --list coverage.info
genhtml coverage.info --output-directory out-coverage --show-details
#- coveralls -r .. --gcov-options '\-lp' -E ".*CMakeFiles.*"

open ${PWD}/out-coverage/index.html
