cmake_minimum_required(VERSION 3.7)

#-------------------------------------------------------------------------------
# Serach source files
#-------------------------------------------------------------------------------
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/commonconnection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mylabel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/streamerthread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tcpclient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
)
file(GLOB UIS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)

#-------------------------------------------------------------------------------
# compile Debug Mode
#-------------------------------------------------------------------------------
add_executable(${NAME_PROJECT} ${SOURCES} ${UIS})
target_link_libraries(${NAME_PROJECT} Qt5::Widgets Qt5::Network logger neuralnetwork)
target_compile_options(${NAME_PROJECT} PRIVATE -fstack-protector-strong
        -Wunused
        -Wshadow
)
if (CMAKE_BUILD_TYPE MATCHES "Debug")
	if(COVERAGE)
		target_link_libraries(coverage)
	endif()
	else()
	target_compile_options(${NAME_PROJECT} PUBLIC -fpic -O2)
endif()
