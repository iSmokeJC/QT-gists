cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME cross)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES main.cpp Widget.cpp Widget.h)
#qt5_add_resources(RCC_SOURCES resources/res.qrc)
#add_executable(${PROJECT_NAME} ${RCC_SOURCES} ${SOURCE_FILES})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
