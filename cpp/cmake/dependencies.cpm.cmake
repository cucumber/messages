if(CUCUMBER_MESSAGES_FETCH_DEPS)
    # ---------------------------------------------------------------------------
    # CPM – download on first configure if not already cached (standalone only)
    # ---------------------------------------------------------------------------
    set(CPM_DOWNLOAD_VERSION 0.40.2)
    set(CPM_DOWNLOAD_LOCATION
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

    if(NOT EXISTS "${CPM_DOWNLOAD_LOCATION}")
        message(STATUS "Downloading CPM.cmake ${CPM_DOWNLOAD_VERSION}…")
        file(DOWNLOAD
            "https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake"
            "${CPM_DOWNLOAD_LOCATION}"
            TLS_VERIFY ON
        )
    endif()

    include("${CPM_DOWNLOAD_LOCATION}")

    # ---------------------------------------------------------------------------
    # Dependencies
    # ---------------------------------------------------------------------------
    CPMAddPackage(
        NAME nlohmann_json
        GITHUB_REPOSITORY nlohmann/json
        GIT_TAG v3.12.0
        OPTIONS "JSON_BuildTests OFF" "JSON_Install ON"
        SYSTEM
    )
    if(nlohmann_json_ADDED)
        # Make the generated config file discoverable by cucumber_messages' find_package()
        list(APPEND CMAKE_PREFIX_PATH "${nlohmann_json_BINARY_DIR}")
    endif()
endif()
