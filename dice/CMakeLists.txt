cmake_minimum_required(VERSION 3.1.0)

project(dice_by_cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(dice_by_cmake
    dice.cpp
    dicewindow.cpp
    main.cpp
    images.qrc
)

target_link_libraries(dice_by_cmake Qt5::Widgets)
