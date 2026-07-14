# renovate: datasource=github-tags packageName=cpm-cmake/CPM.cmake versioning=semver
set(CPM_DOWNLOAD_TAG_DIGEST v0.43.1 456cb6754daaa010d57444d0c8ce6d95ecf006ab)
# renovate: datasource=github-tags packageName=nlohmann/json versioning=semver
set(NLOHMANN_JSON_TAG_DIGEST v3.12.0 55f93686c01528224f448c19128836e7df245f72)
# renovate: datasource=github-tags packageName=google/googletest versioning=semver
set(GOOGLE_TEST_TAG_DIGEST v1.17.0 52eb8108c5bdec04579160ae17225d66034bd723)

list(GET CPM_DOWNLOAD_TAG_DIGEST 0 CPM_DOWNLOAD_TAG)
list(GET CPM_DOWNLOAD_TAG_DIGEST 1 CPM_DOWNLOAD_DIGEST)
string(SUBSTRING CPM_DOWNLOAD_TAG 1 -1 CPM_DOWNLOAD_VERSION)

list(GET NLOHMANN_JSON_TAG_DIGEST 0 NLOHMANN_JSON_TAG)
list(GET NLOHMANN_JSON_TAG_DIGEST 1 NLOHMANN_JSON_DIGEST)
string(SUBSTRING NLOHMANN_JSON_TAG 1 -1 NLOHMANN_JSON_VERSION)


list(GET GOOGLE_TEST_TAG_DIGEST 0 GOOGLE_TEST_TAG)
list(GET GOOGLE_TEST_TAG_DIGEST 1 GOOGLE_TEST_DIGEST)
string(SUBSTRING GOOGLE_TEST_TAG 1 -1 GOOGLE_TEST_VERSION)


if(CUCUMBER_MESSAGES_FETCH_DEPS)
    if(NOT COMMAND CPMAddPackage)
        # ---------------------------------------------------------------------------
        # CPM – download on first configure if not already cached (standalone only)
        # ---------------------------------------------------------------------------
        set(CPM_USE_LOCAL_PACKAGES ON)
        set(CPM_DOWNLOAD_LOCATION "${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

        if(NOT EXISTS "${CPM_DOWNLOAD_LOCATION}")
            message(STATUS "Downloading CPM.cmake ${CPM_DOWNLOAD_VERSION}…")
            file(DOWNLOAD
                "https://github.com/cpm-cmake/CPM.cmake/releases/download/${CPM_DOWNLOAD_TAG}/CPM.cmake"
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
        URI "gh:nlohmann/json@${NLOHMANN_JSON_VERSION}#${NLOHMANN_JSON_DIGEST}"
        NAME nlohmann_json
        OPTIONS
            "JSON_BuildTests Off"
            "JSON_Install ON"
    )

    if(nlohmann_json_ADDED)
        # Make the generated config file discoverable by cucumber_messages' find_package()
        list(APPEND CMAKE_PREFIX_PATH "${nlohmann_json_BINARY_DIR}")
        if(NOT PROJECT_IS_TOP_LEVEL)
            set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" PARENT_SCOPE)
        endif()

        # Propagate nlohmann_json install rules so 'cmake --install' also installs it
        install(SCRIPT "${nlohmann_json_BINARY_DIR}/cmake_install.cmake")
    endif()

    if (CUCUMBER_MESSAGES_BUILD_TESTS)
        CPMAddPackage(
            URI "gh:google/googletest@${GOOGLE_TEST_VERSION}#${GOOGLE_TEST_DIGEST}"
            NAME googletest
            OPTIONS
                "INSTALL_GTEST OFF"
                "gtest_force_shared_crt ON"
        )

        set_target_properties(gtest gtest_main gmock gmock_main PROPERTIES
            FOLDER External/GoogleTest
        )
    endif()
else()
    find_package(nlohmann_json ${NLOHMANN_JSON_VERSION} REQUIRED)

    if (CUCUMBER_MESSAGES_BUILD_TESTS)
        find_package(GTest ${GOOGLE_TEST_VERSION} REQUIRED)
    endif()
endif()
