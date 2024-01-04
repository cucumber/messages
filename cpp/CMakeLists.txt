cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(cucumber_messages VERSION 0.1.0 LANGUAGES C CXX)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(nlohmann_json CONFIG REQUIRED)

add_subdirectory(src/lib/messages)

install(
    TARGETS
        cucumber_messages_lib
    EXPORT cucumber_messages-config
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT cucumber_messages-config
    FILE cucumber_messages-config.cmake
    NAMESPACE cucumber::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cucumber_messages
)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/include/messages/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cucumber
)
