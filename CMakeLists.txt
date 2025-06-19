cmake_minimum_required(VERSION 3.31)
project(TimerApp)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_PATH "/Users/eliamattesini/Qt/6.10.0/macos")
set(CMAKE_PREFIX_PATH ${QT_PATH})

find_package(Qt6 REQUIRED COMPONENTS Widgets Test)

include_directories(include)

add_executable(TimerApp
        main.cpp
        src/Timer.cpp
        src/TimerWindow.cpp
        include/Timer.h
        include/TimerWindow.h
        resources.qrc
)

target_link_libraries(TimerApp
        Qt6::Widgets
)

add_executable(TimerTests
        test/main_test.cpp
        test/test_timer.cpp
        test/test_timerwindow.cpp
        src/Timer.cpp
        src/TimerWindow.cpp
        include/Timer.h
        include/TimerWindow.h
        test/test_timer.h
        test/test_timerwindow.h
)

target_link_libraries(TimerTests
        Qt6::Test
        Qt6::Widgets
)
