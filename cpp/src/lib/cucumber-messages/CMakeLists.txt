add_library(cucumber-messages)
add_library(cucumber::messages ALIAS cucumber-messages)


# We prefer it that way...
file(GLOB_RECURSE CUCUMBER_MESSAGES_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.[ch]pp)

target_sources(
    cucumber-messages
    PRIVATE
        ${CUCUMBER_MESSAGES_SOURCES}
)

target_link_libraries(
    cucumber-messages
    PUBLIC
        cucumber::messages-include
        nlohmann_json::nlohmann_json
)

set_target_properties(
    cucumber-messages
    PROPERTIES
    OUTPUT_NAME cucumber_messages
)
