add_executable(cucumber_messages_lib.test)

target_link_libraries(cucumber_messages_lib.test PRIVATE
    cucumber_messages_lib
    GTest::gmock_main
)

target_compile_definitions(cucumber_messages_lib.test PRIVATE
    CUCUMBER_MESSAGES_TESTDATA_FOLDER="${CMAKE_SOURCE_DIR}/../testdata/src"
)

target_sources(cucumber_messages_lib.test PRIVATE
    TestMessages.cpp
)

include(GoogleTest)
gtest_discover_tests(cucumber_messages_lib.test)

if(CUCUMBER_MESSAGES_ENABLE_MUTATION)
    add_custom_target(mutation-test
        COMMAND ${MULL_RUNNER} $<TARGET_FILE:cucumber_messages_lib.test> --mutation-score-threshold 85
        DEPENDS cucumber_messages_lib.test
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        USES_TERMINAL
    )
endif()
