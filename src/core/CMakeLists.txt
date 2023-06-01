cmake_minimum_required(VERSION 3.14)

project(core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC  common.h )

set_target_properties(${PROJECT_NAME}  PROPERTIES LINKER_LANGUAGE CXX)


