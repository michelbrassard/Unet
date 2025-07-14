cmake_minimum_required(VERSION 3.14)
project(Unet)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Qt6_DIR "/Users/michelbrassard/Qt/6.9.1/macos/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Unet main.cpp)
target_link_libraries(Unet Qt6::Widgets)