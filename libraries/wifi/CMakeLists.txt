add_library(wifi "wifi.cpp")
target_include_directories(wifi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(wifi PRIVATE idf::esp_wifi)