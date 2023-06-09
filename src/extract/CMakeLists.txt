cmake_minimum_required(VERSION 3.14)

project(extract LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(${PROJECT_NAME} STATIC
        include/Helper.h
        include/Logger.h
        Helper.cpp
        Logger.cpp
        include/Extract.h
        Extract.cpp
        ExtractFactory.cpp
        include/ExtractFactory.h
        include/ChapterTypes.h
        include/ExtractionMode.h

)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core core)
