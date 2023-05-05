add_library(cucumber-messages)
add_library(cucumber::messages ALIAS cucumber-messages)

set(INC_DIR "${CMAKE_SOURCE_DIR}/include")

# We prefer it that way...
file(GLOB_RECURSE CUCUMBER_MESSAGES_HEADERS ${INC_DIR}/*.[ch]pp)
file(GLOB_RECURSE CUCUMBER_MESSAGES_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.[ch]pp)

target_sources(
    cucumber-messages
    PUBLIC
    FILE_SET
        "cucumber_messages_headers"
        TYPE HEADERS
        BASE_DIRS ${INC_DIR}
        FILES
        ${CUCUMBER_MESSAGES_HEADERS}
    PRIVATE
        ${CUCUMBER_MESSAGES_SOURCES}
)

target_include_directories(
    cucumber-messages
    INTERFACE
        $<BUILD_INTERFACE:${INC_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/cucumber>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(
    cucumber-messages
    PROPERTIES
    OUTPUT_NAME cucumber_messages
)
