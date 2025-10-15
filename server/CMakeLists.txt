cmake_minimum_required(VERSION 3.10)

project(Remote_System_Monitor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED True)

find_package(RapidJSON REQUIRED)

set(SOURCES 
    src/main.cpp
    src/server.cpp
    src/system_monitor.cpp
)

add_executable(server ${SOURCES})

target_include_directories(server
    PRIVATE
        include
)

target_compile_options(server PRIVATE -Wall -Wextra -Wpedantic)
