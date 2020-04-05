cmake_minimum_required (VERSION 3.16)
project(QtTcpSocket LANGUAGES CXX)
set(NAME_PROJECT "Receiver")

include(cmake/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
    )
enable_testing()

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
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Check architecture
EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE )


#-------------------------------------------------------------------------------
# Select external Library
#-------------------------------------------------------------------------------
set(HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vendor/tensorflow-lite/include" CACHE INTERNAL "")
include_directories(${HEADERS_PATH})

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND "${ARCHITECTURE}" STREQUAL "aarch64")
	set(LIBRARYPATH "${CMAKE_CURRENT_SOURCE_DIR}/vendor/tensorflow-lite/aarch64_armv8-a/lib" CACHE INTERNAL "")
    message(STATUS "Detect os: ${CMAKE_SYSTEM_NAME}\tarch: ${ARCHITECTURE}")
    message(STATUS "Set library's directory: ${LIBRARYPATH}")
    link_directories(${LIBRARYPATH})
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND "${ARCHITECTURE}" STREQUAL "armv7l")
	set(LIBRARYPATH "${CMAKE_CURRENT_SOURCE_DIR}/vendor/tensorflow-lite/rpi_armv7l/lib" CACHE INTERNAL "")
    message(STATUS "Detect os: ${CMAKE_SYSTEM_NAME}\tarch: ${ARCHITECTURE}")
    message(STATUS "Set library's directory: ${LIBRARYPATH}")
    link_directories(${LIBRARYPATH})
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" AND "${ARCHITECTURE}" STREQUAL "x86_64")
    set(LIBRARYPATH "${CMAKE_CURRENT_SOURCE_DIR}/vendor/tensorflow-lite/osx_x86_64/lib" CACHE INTERNAL "")
    message(STATUS "Detect os: ${CMAKE_SYSTEM_NAME}\tarch: ${ARCHITECTURE}")
    message(STATUS "Set library's directory: ${LIBRARYPATH}")
    link_directories(${LIBRARYPATH})
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND "${ARCHITECTURE}" STREQUAL "x86_64")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND "${ARCHITECTURE}" STREQUAL "armv7l")
	#-----------------------------------------------------------------------------
	# Specific Flag for RaspBerry Pi 3 
	#-----------------------------------------------------------------------------
	set(CMAKE_C_FLAGS_DEBUG "-march=armv8-a+crc -mtune=cortex-a53 -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -ftree-vectorize -funsafe-math-optimizations -pipe -pthread")
	set(CMAKE_CXX_FLAGS_DEBUG "-march=armv8-a+crc -mtune=cortex-a53 -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -ftree-vectorize -funsafe-math-optimizations -pipe -pthread")
	set(CMAKE_C_FLAGS_RELEASE "-march=armv8-a+crc -mtune=cortex-a53 -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -ftree-vectorize -funsafe-math-optimizations -pipe -pthread")
	set(CMAKE_CXX_FLAGS_RELEASE "-march=armv8-a+crc -mtune=cortex-a53 -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -ftree-vectorize -funsafe-math-optimizations -pipe -pthread")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" AND "${ARCHITECTURE}" STREQUAL "x86_64")
	#-----------------------------------------------------------------------------
	# Specific Flag for MacOS
	#-----------------------------------------------------------------------------	
	set(CMAKE_C_FLAGS_DEBUG "-march=native -pthread")
	set(CMAKE_CXX_FLAGS_DEBUG "-march=native -pthread")
	set(CMAKE_C_FLAGS_RELEASE "-march=native -pthread")
	set(CMAKE_CXX_FLAGS_RELEASE "-march=native -pthread")
endif()

#-----------------------------------------------------------------------------
# Code coverage
#-----------------------------------------------------------------------------
if(COVERAGE)
	message(STATUS "Coverage: ON")
	add_library(coverage INTERFACE)
	if(${CMAKE_BUILD_TYPE} STREQUAL "Debug" AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	  	message(STATUS "enabled coverage")
	  	# Add required flags (GCC & LLVM/Clang)
	  	target_compile_options(coverage INTERFACE
			-O0        # no optimization
			-g         # generate debug info
			-ftest-coverage -fprofile-arcs # sets all required flags
	  	)
	  	if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
			target_link_options(coverage INTERFACE --coverage)
	  	else()
			target_link_libraries(coverage INTERFACE --coverage)
	  	endif()
	endif()
endif()


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

#-----------------------------------------------------------------------------
# Library and Dependecies
#-----------------------------------------------------------------------------
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

#-----------------------------------------------------------------------------
# Local library and dependecies
#-----------------------------------------------------------------------------
add_subdirectory(src)
add_subdirectory(log)
add_subdirectory(tf)
add_subdirectory(test)

# ----------------------------------------------------------------------------
# display status message for important variables
# ----------------------------------------------------------------------------
message( STATUS )
message( STATUS "-------------------------------------------------------------------------------" )
message( STATUS "General configuration for ${PROJECT_NAME} ${PROJECT_VERSION}")
message( STATUS "-------------------------------------------------------------------------------" )
message( STATUS )
message( STATUS "Architecture:\t${ARCHITECTURE}" )
message( STATUS "Compiler:\t${CMAKE_COMPILER}\t${CMAKE_CXX_COMPILER}")
message( STATUS "C flags (Release): \t${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE}")
message( STATUS "C flags (Debug): \t${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG}")
message( STATUS "C++ flags (Release):\t${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
message( STATUS "C++ flags (Debug):\t${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
message( STATUS "CMAKE_BINARY_DIR:\t${CMAKE_BINARY_DIR}")
message( STATUS )
message( STATUS "Change a value with: cmake -D<Variable>=<Value> .." )
message( STATUS )

# ----------------------------------------------------------------------------
# copy resources
# ----------------------------------------------------------------------------
file(INSTALL ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/src)
file(INSTALL ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test)
