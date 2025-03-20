cmake_minimum_required(VERSION 3.10)
project(Client)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)


add_executable(client src/main.cpp src/client.cpp)

find_package(Threads REQUIRED)
target_link_libraries(client PRIVATE Threads::Threads)
