add_executable(
  unit_tests
  test_loadmodel.cpp
  test_cocolabels.cpp
  test_imagenetlabels.cpp
  test_genericlabels.cpp
  test_inference.cpp
  test_color.cpp
)

target_link_libraries(
  unit_tests
  gtest_main
  Qt5::Widgets
  neuralnetwork
)

if(COVERAGE)
  target_link_libraries(unit_tests coverage)
endif(COVERAGE)

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
