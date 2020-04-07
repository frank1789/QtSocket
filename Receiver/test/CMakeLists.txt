add_executable(
  unit_tests
  test_loadmodel.cpp
  test_labels.cpp
  test_genericlabels.cpp
  test_inference.cpp
)

target_link_libraries(
  unit_tests
  gtest_main
  Qt5::Widgets
  neuralnetwork
  coverage
)

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
