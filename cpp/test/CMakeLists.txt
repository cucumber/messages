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
