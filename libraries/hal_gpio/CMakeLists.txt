add_library(hal_gpio "hal_gpio.cpp")
target_include_directories(hal_gpio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(hal_gpio PRIVATE idf::driver)