###
#
# Project
# name and version
#
###
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(cucumber_messages VERSION 28.0.0 LANGUAGES C CXX)

###
#
# Main project check
#
###
set(cucumber_messages_MAIN_PROJECT OFF)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(cucumber_messages_MAIN_PROJECT ON)
endif()

###
#
# Options
#
###
if(${CUCUMBER_MESSAGES_MAIN_PROJECT})
    set(CUCUMBER_MESSAGES_BUILD_TESTS_INIT ON)
    set(CUCUMBER_MESSAGES_EXPORT_COMPILE_INIT ON)
else()
    set(CUCUMBER_MESSAGES_BUILD_TESTS_INIT OFF)
    set(CUCUMBER_MESSAGES_EXPORT_COMPILE_INIT OFF)
endif()

option(
    CUCUMBER_MESSAGES_BUILD_TESTS
    "Build the unit tests."
    ${CUCUMBER_MESSAGES_BUILD_TESTS_INIT}
)

option(
    CUCUMBER_MESSAGES_EXPORT_COMPILE
    "Export compile commands."
    ${CUCUMBER_MESSAGES_EXPORT_COMPILE_INIT}
)

option(
    CUCUMBER_MESSAGES_FETCH_DEPS
    "Fetch dependencies via FetchContent."
    ${CUCUMBER_MESSAGES_FETCH_DEPS}
)

###
#
# Configuration
#
###
include(GNUInstallDirs)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS _SCL_SECURE_NO_WARNINGS)
endif()

if(CUCUMBER_MESSAGES_EXPORT_COMPILE)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

###
#
# CMake dependencies
#
###
if(CUCUMBER_MESSAGES_FETCH_DEPS)
    include(FetchContent)

    FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3
        OVERRIDE_FIND_PACKAGE
    )

    set(JSON_BuildTests "OFF")
    set(JSON_Install "ON")

    FetchContent_MakeAvailable(nlohmann_json)
endif()

find_package(nlohmann_json CONFIG REQUIRED)

###
#
# Targets
#
###
add_subdirectory(src/lib/messages)

###
#
# Installation support
#
###
include(CMakePackageConfigHelpers)

configure_package_config_file(
  "cmake/cucumber_messages-config.cmake.in"
  "${PROJECT_BINARY_DIR}/cucumber_messages-config.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/cucumber_messages"
  PATH_VARS CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR
)

write_basic_package_version_file(
  "${PROJECT_BINARY_DIR}/cucumber_messages-config-version.cmake"
  COMPATIBILITY AnyNewerVersion
)

install(
    TARGETS
        cucumber_messages_lib
    EXPORT cucumber_messages-targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT cucumber_messages-targets
    FILE cucumber_messages-targets.cmake
    NAMESPACE cucumber::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/cucumber_messages"
)

install(
    FILES
        "${PROJECT_BINARY_DIR}/cucumber_messages-config.cmake"
        "${PROJECT_BINARY_DIR}/cucumber_messages-config-version.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/cucumber_messages"
)


install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/include/messages/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cucumber
)
