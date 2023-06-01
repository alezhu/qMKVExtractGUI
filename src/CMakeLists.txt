cmake_minimum_required(VERSION 3.5)

add_subdirectory(core)
include_directories(${core_SOURCE_DIR})
add_subdirectory(extract)
add_subdirectory(model)
add_subdirectory(ui)





