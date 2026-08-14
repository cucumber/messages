cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(cucumber_messages_test_package LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(cucumber_messages REQUIRED)

add_executable(cucumber_messages_test_package main.cpp)
target_link_libraries(cucumber_messages_test_package PRIVATE cucumber::messages)

enable_testing()
add_test(NAME cucumber_messages_test_package COMMAND cucumber_messages_test_package)
