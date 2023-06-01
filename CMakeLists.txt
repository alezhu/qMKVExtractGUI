cmake_minimum_required(VERSION 3.5)

project(qMKVExtractGUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "e:\\Soft\\Qt\\6.5.0\\mingw_64")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(src)

set(APP_PROJECT_SOURCES
   src/main.cpp
   src/app.rc
   src/app.qrc
)

find_package(Qt6 REQUIRED COMPONENTS Core)
qt_add_executable(${PROJECT_NAME}
    MANUAL_FINALIZATION
    ${APP_PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME}  PRIVATE core extract model ui )

set_target_properties(${PROJECT_NAME}  PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER qmkvextracgui.alezhu.ru
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

qt_finalize_executable(${PROJECT_NAME})
