cmake_minimum_required(VERSION 3.10)

project(Remote_System_Monitor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
    rapidjson
    GIT_REPOSITORY https://github.com/Tencent/rapidjson.git
    GIT_TAG master
)
FetchContent_MakeAvailable(rapidjson)

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

add_library(rapidjson_lib INTERFACE)
target_include_directories(rapidjson_lib INTERFACE ${rapidjson_SOURCE_DIR}/include)

target_link_libraries(server PRIVATE rapidjson_lib)

target_compile_options(server PRIVATE -Wall -Wextra -Wpedantic)
