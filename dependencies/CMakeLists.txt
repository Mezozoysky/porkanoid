# if(PDCLI_BUILD_UT)
    # add_subdirectory(Catch2)
    # set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" PARENT_SCOPE)
    # include(CTest)
    # include(Catch)
# endif()

#if(PDCLI_FMT_BUNDLED)
#    add_subdirectory(fmt)
#else()
#    find_package(fmt 7.0.3...9.1.0 REQUIRED)
#endif()

#if(PDCLI_SPDLOG_BUNDLED)
#    # set(SPDLOG_FMT_EXTERNAL TRUE)
#    add_subdirectory(spdlog)
#else()
#    find_package(spdlog 1.7.1...1.11.0 REQUIRED)
#endif()

set(SFML_STATIC_LIBRARIES TRUE)
add_subdirectory(SFML)

