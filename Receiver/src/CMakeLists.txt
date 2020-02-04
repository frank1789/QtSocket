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
add_definitions(-DLOGGER -DLOGGER_CLIENT -DTEST_IMAGE)
target_link_libraries(${NAME_PROJECT}
  Qt5::Widgets
  Qt5::Network
  ${CMAKE_THREAD_LIBS_INIT}
  # coverage_config
  logger)
target_compile_options(${NAME_PROJECT} PUBLIC -fpic -O2)
