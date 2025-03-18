cmake_minumum_required(VERSION 3.10)

project(Remote_System_Monitor)

set(CMAKE_CXX_STANDARD 20)

add_executable(server src/server.cpp src/system_monitor.cpp)
add_executable(client src/client.cpp)


SET(CMAKE_BUILD_TYPE "Debug")