add_library(cucumber_messages_lib)
add_library(cucumber::messages ALIAS cucumber_messages_lib)

set(CUCUMBER_MESSAGES_LIB_INC_DIR "${PROJECT_SOURCE_DIR}/include/messages")
file(GLOB_RECURSE CUCUMBER_MESSAGES_LIB_HEADERS ${CUCUMBER_MESSAGES_LIB_INC_DIR}/*.hpp)
list(APPEND CUCUMBER_MESSAGES_LIB_ALL_SOURCES ${CUCUMBER_MESSAGES_LIB_HEADERS})

set(CUCUMBER_MESSAGES_LIB_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB_RECURSE CUCUMBER_MESSAGES_LIB_SOURCES ${CUCUMBER_MESSAGES_LIB_SRC_DIR}/*.[ch]pp)
list(APPEND CUCUMBER_MESSAGES_LIB_ALL_SOURCES ${CUCUMBER_MESSAGES_LIB_SOURCES})

target_sources(
    cucumber_messages_lib
    PRIVATE
        ${CUCUMBER_MESSAGES_LIB_ALL_SOURCES}
)

target_include_directories(
    cucumber_messages_lib
    PUBLIC
        $<BUILD_INTERFACE:${CUCUMBER_MESSAGES_LIB_INC_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
    cucumber_messages_lib
    PUBLIC
        nlohmann_json::nlohmann_json
)

set_target_properties(
    cucumber_messages_lib
    PROPERTIES
        VERSION 0.1.0
        SOVERSION 0.1
        EXPORT_NAME messages
        OUTPUT_NAME cucumber_messages
)
