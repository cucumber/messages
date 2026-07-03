if(CUCUMBER_MESSAGES_FETCH_DEPS)
    if(NOT COMMAND CPMAddPackage)
        # ---------------------------------------------------------------------------
        # CPM – download on first configure if not already cached (standalone only)
        # ---------------------------------------------------------------------------
        set(CPM_DOWNLOAD_VERSION 0.40.2)
        set(CPM_USE_LOCAL_PACKAGES ON)
        set(CPM_DOWNLOAD_LOCATION "${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

        if(NOT EXISTS "${CPM_DOWNLOAD_LOCATION}")
            message(STATUS "Downloading CPM.cmake ${CPM_DOWNLOAD_VERSION}…")
            file(DOWNLOAD
                "https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake"
                "${CPM_DOWNLOAD_LOCATION}"
                TLS_VERIFY ON
            )
        endif()

        include("${CPM_DOWNLOAD_LOCATION}")
    endif()

    # ---------------------------------------------------------------------------
    # Dependencies
    # ---------------------------------------------------------------------------
    CPMAddPackage(
        NAME nlohmann_json
        GITHUB_REPOSITORY nlohmann/json
        GIT_TAG v3.12.0
        OPTIONS "JSON_BuildTests OFF" "JSON_Install ON"
    )

    if(TARGET nlohmann_json)
        set_target_properties(nlohmann_json PROPERTIES SYSTEM ON)
    endif()

    if(nlohmann_json_ADDED)
        # Make the generated config file discoverable by cucumber_messages' find_package()
        list(APPEND CMAKE_PREFIX_PATH "${nlohmann_json_BINARY_DIR}")
        if(NOT cucumber_messages_MAIN_PROJECT)
            set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" PARENT_SCOPE)
        endif()
    endif()

    if(CUCUMBER_MESSAGES_BUILD_TESTS)
        CPMAddPackage(
            NAME googletest
            GITHUB_REPOSITORY google/googletest
            GIT_TAG 52eb8108c5bdec04579160ae17225d66034bd723 # v1.17.0
            OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt ON"
        )

        set_target_properties(gtest gtest_main gmock gmock_main PROPERTIES
            FOLDER External/GoogleTest
            SYSTEM ON
        )
    endif()
else()
    find_package(nlohmann_json 3.12.0 REQUIRED)
endif()
