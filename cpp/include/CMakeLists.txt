add_library(cucumber-messages-include INTERFACE)
add_library(cucumber::messages-include ALIAS cucumber-messages-include)

set(INC_DIR "${CMAKE_CURRENT_LIST_DIR}")

# We prefer it that way...
file(GLOB_RECURSE GHERKIN_CPP_HEADERS ${INC_DIR}/*.[ch]pp)

target_sources(
    cucumber-messages-include
    PRIVATE
        ${GHERKIN_CPP_HEADERS}
)

target_include_directories(
    cucumber-messages-include
    INTERFACE
        $<BUILD_INTERFACE:${INC_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/cucumber>
)

target_link_libraries(
    cucumber-messages-include
    INTERFACE
        nlohmann_json::nlohmann_json
)
