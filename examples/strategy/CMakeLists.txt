cmake_minimum_required(VERSION 3.10)

project (strategy VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

file(GLOB SRC_FILES "src/*.cpp")

add_executable (strategy.exe ${SRC_FILES})

target_compile_options(strategy.exe PRIVATE -Wall -Wextra -Wpedantic)