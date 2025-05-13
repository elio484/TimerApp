cmake_minimum_required(VERSION 3.31)
project(TimerApp)

set(CMAKE_CXX_STANDARD 20)

# Serve per abilitare la generazione automatica di moc, uic, ecc.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/eliamattesini/Qt/6.10.0/macos")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(include)

add_executable(TimerApp
        main.cpp
        include/TimerWindow.h
        src/TimerWindow.cpp
        resources.qrc
)

target_link_libraries(TimerApp Qt6::Widgets)
