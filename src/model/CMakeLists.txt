cmake_minimum_required(VERSION 3.14)

project(model LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(${PROJECT_NAME} STATIC
  include/Model.h
  include/Settings.h
  include/SettingsManager.h
  Model.cpp
  Settings.cpp
  SettingsManager.cpp

  SettingsManager_p.h
  SettingsManager_p.cpp

  SettingsFilter.h
  SettingsFilter.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include )
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core core extract)

