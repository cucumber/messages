cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(cucumber-messages VERSION 1.0.0 LANGUAGES C CXX)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(src)

install(
    TARGETS
        cucumber-messages
    EXPORT cucumber-messages-config
    FILE_SET cucumber_messages_headers
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT cucumber-messages-config
    FILE cucumber-messages-config.cmake
    NAMESPACE cucumber::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cucumber-messages
)
