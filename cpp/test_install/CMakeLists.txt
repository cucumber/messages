cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(cucumber_messages_test_install VERSION 1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(cucumber_messages REQUIRED)
add_executable(cucumber_messages_test_install main.cpp)
target_link_libraries(cucumber_messages_test_install PRIVATE cucumber::messages)
