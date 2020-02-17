cmake_minimum_required(VERSION 3.7)

#-------------------------------------------------------------------------------
# Serach source files
#-------------------------------------------------------------------------------
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB UIS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)

#-------------------------------------------------------------------------------
# compile Debug Mode
#-------------------------------------------------------------------------------
add_executable(${NAME_PROJECT} ${SOURCES} ${UIS})
target_link_libraries(${NAME_PROJECT} Qt5::Widgets Qt5::Network logger neural)
if (CMAKE_BUILD_TYPE MATCHES "Debug")
	target_compile_options(${NAME_PROJECT} PUBLIC -fpic -O0 -g)
	add_definitions(-D LOGGER_UI)
	if(COVERAGE)
		target_link_libraries(coverage_config)
	endif()
	else()
	target_compile_options(${NAME_PROJECT} PUBLIC -fpic -O2)
endif()
