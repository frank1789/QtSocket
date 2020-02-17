cmake_minimum_required(VERSION 3.7)



if(APPLE)
set(LIB_FILE ${CMAKE_CURRENT_SOURCE_DIR}/tensorflow-lite/osx_x86_64/lib/libtensorflow-lite.a)
endif()


# define include folder
set(LIB_HEADER_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/tensorflow-lite/include)

# create custom target
add_custom_target(tflite_target DEPENDS ${LIB_FILE})

# create an library target out of the library compilation result
add_library(tflite STATIC IMPORTED GLOBAL)
add_dependencies(tflite tflite_target)

# specify where the library is and where to find the headers
set_target_properties(tflite
    PROPERTIES
    IMPORTED_LOCATION ${LIB_FILE}
    INTERFACE_INCLUDE_DIRECTORIES ${LIB_HEADER_FOLDER})


