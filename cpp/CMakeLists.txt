cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(cucumber_messages VERSION 0.1.0 LANGUAGES C CXX)

include(GNUInstallDirs)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS _SCL_SECURE_NO_WARNINGS)
endif()

set(${CUCUMBER_MESSAGES_LOCAL_DEV} OFF)

if(${CUCUMBER_MESSAGES_LOCAL_DEV})
    set(CUCUMBER_MESSAGES_BUILD_TESTS_INIT ON)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
else()
    set(CUCUMBER_MESSAGES_BUILD_TESTS_INIT OFF)
endif()

option(CUCUMBER_MESSAGES_BUILD_TESTS "Build the unit tests." ${CUCUMBER_MESSAGES_BUILD_TESTS_INIT})


find_package(nlohmann_json CONFIG REQUIRED)
add_subdirectory(src/lib/messages)
if(CUCUMBER_MESSAGES_BUILD_TESTS)
    include(CTest)
    enable_testing()
endif()


install(
    TARGETS
        cucumber_messages_lib
    EXPORT cucumber_messages-config
    RUNTIME DESTINATION \${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION \${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION \${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT cucumber_messages-config
    FILE cucumber_messages-config.cmake
    NAMESPACE cucumber::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cucumber_messages
)
