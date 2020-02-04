cmake_minimum_required (VERSION 3.7)
project(QtTcpSocket LANGUAGES CXX)
set(NAME_PROJECT "Sender")

#-----------------------------------------------------------------------------
# check build type
#-----------------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
        message(STATUS "Compile in debug mode")
        set(CMAKE_BUILD_TYPE Debug)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
        set(CMAKE_BUILD_TYPE Debug)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
        set(CMAKE_BUILD_TYPE Release)
endif()

#-----------------------------------------------------------------------------
# C/C++ standard extensions
#-----------------------------------------------------------------------------
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#-----------------------------------------------------------------------------
# Specific Flag for RaspBerry Pi 3
#-----------------------------------------------------------------------------
#set(CMAKE_C_FLAGS_DEBUG "-march=armv8-a+crc -mtune=cortex-a53 -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -ftree-vectorize -funsafe-math-optimizations -pipe")
#set(CMAKE_CXX_FLAGS_DEBUG "-march=armv8-a+crc -mtune=cortex-a53 -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -ftree-vectorize -funsafe-math-optimizations -pipe")
#set(CMAKE_C_FLAGS_RELEASE "-march=armv8-a+crc -mtune=cortex-a53 -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -ftree-vectorize -funsafe-math-optimizations -pipe")
#set(CMAKE_CXX_FLAGS_RELEASE "-march=armv8-a+crc -mtune=cortex-a53 -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -ftree-vectorize -funsafe-math-optimizations -pipe")

#-----------------------------------------------------------------------------
# Code coverage
#-----------------------------------------------------------------------------
if(COVERAGE)
        add_library(coverage_config INTERFACE)
        if(${CMAKE_BUILD_TYPE} STREQUAL "Debug" AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
                message(STATUS "enabled coverage")
                # Add required flags (GCC & LLVM/Clang)
                target_compile_options(coverage_config INTERFACE
                        -O0        # no optimization
                        -g         # generate debug info
                        -ftest-coverage -fprofile-arcs # sets all required flags
                )
                if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
                        target_link_options(coverage_config INTERFACE --coverage)
                else()
                        target_link_libraries(coverage_config INTERFACE --coverage)
                endif()
        endif()
endif()

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

#-------------------------------------------------------------------------------
# Build Documentation
#-------------------------------------------------------------------------------
# check if Doxygen is installed
# find_package(Doxygen)
# if (DOXYGEN_FOUND)
#     # set input and output files
#     set(DOXYGEN_IN  ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
#     set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile)
#     # request to configure the file
#     configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#     message("Doxygen build started")
#     # note the option ALL which allows to build the docs together with the application
#     add_custom_target( doc_doxygen ALL
#         COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#         COMMENT "Generating API documentation with Doxygen"
#         VERBATIM )
# else (DOXYGEN_FOUND)
#  message(STATUS "Doxygen need to be installed to generate the doxygen documentation")
# endif (DOXYGEN_FOUND)

# Find the Qt library
if(APPLE AND EXISTS /usr/local/opt/qt5)
	list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt5")
endif()
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
if (${Qt5_FOUND})
   message(STATUS "Found Qt 5")
else (${Qt5_FOUND})
   message(FATAL_ERROR "Could not locate Qt.")
endif (${Qt5_FOUND})

# Find PThread Library
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)

#-------------------------------------------------------------------------------
# Add subdirectories
#-------------------------------------------------------------------------------
add_subdirectory(log)
add_subdirectory(src)
