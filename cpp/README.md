# Cucumber Messages for C++ (JSON schema)

## Requirements

This library requires:
- A C++ 17 compiler (tested with GCC 10, 12)
- [JSON for Modern C++](https://json.nlohmann.me/)

## Installing from Git repository

```shell
$ git clone https://github.com/cucumber/messages
$ cd messages/cpp
$ cmake -S . -B build
$ cmake --build build
$ cmake --install build
```

## CMake integration

```cmake
find_package(cucumber-messages CONFIG REQUIRED)

target_link_libraries(mylib PRIVATE cucumber::cucumber-messages)
```
