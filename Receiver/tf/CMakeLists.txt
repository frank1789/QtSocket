# Simple and fast logger for embedded programs C / C ++ interface
cmake_minimum_required(VERSION 3.7)
set(LIB_NAME "neuralnetwork")


#-------------------------------------------------------------------------------
# Include dirs
#-------------------------------------------------------------------------------
set(HEADERS_PATH "${CMAKE_HOME_DIRECTORY}/vendor/tensorflow-lite/include" CACHE INTERNAL "")
message(STATUS "Search for ${HEADERS_PATH}")
include_directories(${HEADERS_PATH})
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

#-------------------------------------------------------------------------------
# Select external Library
#-------------------------------------------------------------------------------
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND "${ARCHITECTURE}" STREQUAL "x86_64")
	include_directories(${HEADERS_PATH})
	link_directories(vendor/tensorflow-lite/aarch64_armv8-a/lib)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND "${ARCHITECTURE}" STREQUAL "x86_64")
	include_directories(${HEADERS_PATH})
	link_directories(vendor/tensorflow-lite/rpi_armv7l/lib)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" AND "${ARCHITECTURE}" STREQUAL "x86_64")
    set(LIBRARYPATH "${CMAKE_CURRENT_SOURCE_DIR}/tensorflow-lite/osx_x86_64/lib" CACHE INTERNAL "")
    message(STATUS "Detect os: ${CMAKE_SYSTEM_NAME}\tarch: ${ARCHITECTURE}")
    message(STATUS "Set library's directory: ${LIBRARYPATH}")
    link_directories(${LIBRARYPATH})
endif()

#-------------------------------------------------------------------------------
# add library neural network
#-------------------------------------------------------------------------------
set(LIBRARY_TARGET_NAME ${LIB_NAME})
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/colormanager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/findmodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model_tpu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/util_label_image.cpp
)

add_library(${LIB_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${LIB_NAME}
    Qt5::Widgets 
    Qt5::Network 
    logger 
    -ltensorflow-lite
)
target_compile_options(${LIB_NAME} PUBLIC -march=native -fpic -O2)
