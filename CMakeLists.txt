# This file demonstrates an issue with the cmake build system when used as esp as a library
# this is based off of the esp as library project
cmake_minimum_required(VERSION 3.24)

project(pt_controller CXX C ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_CXX_STANDARD 20)


# Include ESP-IDF build system functions
set(targets "esp32" "esp32s2" "esp32s3" "esp32c3" "esp32h2" "esp32c2")
set(EXTRA_COMPONENT_DIRS "$ENV{IDF_PATH}/examples/cxx/experimental/experimental_cpp_component")
include($ENV{IDF_PATH}/tools/cmake/idf.cmake)
if("${TARGET}" IN_LIST targets)
    # Include for ESP-IDF build system functions
    #    include($ENV{IDF_PATH}/tools/cmake/idf.cmake)
    # Create idf::{target} and idf::freertos static libraries

idf_build_process("${TARGET}"
        # try and trim the build; additional components
        # will be included as needed based on dependency tree
        #
        # although esptool_py does not generate static library,
        # processing the component is needed for flashing related
        # targets and file generation
        COMPONENTS freertos esp_wifi esptool_py driver
        SDKCONFIG ${CMAKE_CURRENT_LIST_DIR}/sdkconfig
        BUILD_DIR ${CMAKE_BINARY_DIR})
else()
    message(WARNING "Unknown target ${TARGET}, creating stubs for esp32 instead")
endif()

message("IDF_PATH: $ENV{IDF_PATH}")
add_subdirectory(app)
add_subdirectory(libraries)