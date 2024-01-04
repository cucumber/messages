cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(cucumber-messages VERSION 1.0.0 LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(nlohmann_json CONFIG REQUIRED)

add_subdirectory(include)
add_subdirectory(src)

install(
    TARGETS
        cucumber-messages
        cucumber-messages-include
    EXPORT cucumber-messages-config
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cucumber
)

install(
    EXPORT cucumber-messages-config
    FILE cucumber-messages-config.cmake
    NAMESPACE cucumber::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cucumber-messages
)
