#!/usr/bin/env sh



# ////////////////////////////////////////////////////////////////////////////
# declare function
# ////////////////////////////////////////////////////////////////////////////

compile_debug() {
    DIRECTORY=build_debug
    clear_old_build
    echo "create new directory $DIRECTORY"
    mkdir $DIRECTORY && cd $DIRECTORY
    lcov --directory . --zerocounters
    cmake -D CMAKE_BUILD_TYPE=Debug -D COVERAGE=ON ..
    make -j$(nproc)
    EXECUTABLE=$(find $PWD -name "Receiver")
    ${EXECUTABLE} -platform wayland
	# Create lcov report capturing coverage info
	lcov --directory . --capture --output-file coverage.info
	# filter out system and extra files.
	# To also not include test code in coverage add them with full path to the patterns: '*/tests/*'
	lcov --remove coverage.info '/usr/*' "${HOME}"'/.cache/*' --output-file coverage.info
	# output coverage data for debugging (optional)
	lcov --list coverage.info
	genhtml coverage.info --output-directory out-coverage  --show-details
	#- coveralls -r .. --gcov-options '\-lp' -E ".*CMakeFiles.*"
}

compile_release() {
    DIRECTORY=build_release
    clear_old_build
    echo "create new directory $DIRECTORY"
    mkdir $DIRECTORY && cd $DIRECTORY
    cmake -D CMAKE_BUILD_TYPE=Release ..
    make -j3
    EXECUTABLE=$(find $PWD -name "Receiver")
    ${EXECUTABLE} -platform wayland
}

clear_old_build() {
    DIR_BUILD_DEBUG=build_debug
    DIR_BUILD_RELES=build_release
    # check for previuous debug build
    if [ -d "$DIR_BUILD_DEBUG" ]; then
        echo "remove previus build debug"
        rm -rf $DIR_BUILD_DEBUG

    # check for previus release build
    elif [ -d "$DIR_BUILD_RELES" ]; then
        echo "remove previus build release"
        rm -rf $DIR_BUILD_RELES
    fi

    if [ -d "build" ]; then
        echo "remove previus build"
        rm -rf build
    fi
}

# ////////////////////////////////////////////////////////////////////////////
# main script
# ////////////////////////////////////////////////////////////////////////////

# generate dependecies if not exist
make -f $PWD/Makefile

if [ "$#" -eq "0" ]; then
    echo "build release version"
    compile_release
else
    if [ "$1" = "Debug" ] || [ "$1" = "debug" ]; then
        echo "build debug version"
        compile_debug
    fi
fi
