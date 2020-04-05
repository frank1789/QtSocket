# Simple and fast logger for embedded programs C / C ++ interface
cmake_minimum_required(VERSION 3.7)
set(LIB_NAME "neuralnetwork")

#-------------------------------------------------------------------------------
# add library neural network
#-------------------------------------------------------------------------------
set(LIBRARY_TARGET_NAME ${LIB_NAME})
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/list_colour.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/colormanager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/findmodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model_tpu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/labels_utils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/labels.cpp
)

add_library(${LIB_NAME} "")
target_link_libraries(${LIB_NAME}
    Qt5::Widgets 
    Qt5::Network 
    logger 
    -ltensorflow-lite
)

target_sources(
    ${LIB_NAME}
    PRIVATE
        ${SOURCES}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/list_colour.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/colormanager.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/findmodel.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/model_tpu.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/label_utils.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/labels.hpp
)

target_include_directories(
    ${LIB_NAME} PUBLIC  ${CMAKE_CURRENT_LIST_DIR})

if (CMAKE_BUILD_TYPE MATCHES "Debug")
	if(COVERAGE)
		target_link_libraries(coverage)
	endif()
	else()
	target_compile_options(${NAME_PROJECT} PUBLIC -fpic -O2)
endif()
