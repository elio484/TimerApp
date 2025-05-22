cmake_minimum_required(VERSION 3.31)
project(TimerApp)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/eliamattesini/Qt/6.10.0/macos")

find_package(Qt6 REQUIRED COMPONENTS Widgets Test)

include_directories(include)


add_executable(TimerApp
        main.cpp
        include/TimerWindow.h
        src/TimerWindow.cpp
        resources.qrc
)

target_link_libraries(TimerApp Qt6::Widgets)


add_executable(TimerTests
        test/main_test.cpp
        test/test_timerwindow.cpp
        test/test_timerwindow.h
        src/TimerWindow.cpp
        include/TimerWindow.h
)

target_link_libraries(TimerTests Qt6::Test Qt6::Widgets)
