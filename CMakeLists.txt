if(CMAKE_HOST_WIN32)
    cmake_minimum_required(VERSION 3.24)
else()
    cmake_minimum_required(VERSION 3.22)
endif()

project(PORKANOID
    LANGUAGES CXX
    VERSION 0.1.0
)

set(PORKANOID_VERSION ${PROJECT_VERSION})

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

set(PORKANOID_BUILD_SHARED_DEFAULT ${BUILD_SHARED_LIBS})
set(PORKANOID_BUILD_UT_DEFAULT FALSE)

option(PORKANOID_BUILD_SHARED "Build shared libraries" ${PORKANOID_BUILD_SHARED_DEFAULT})
option(PORKANOID_BUILD_UT "Build unit tests" ${PORKANOID_BUILD_UT_DEFAULT})
#option(PORKANOID_FMT_BUNDLED "Use bundled fmt library" TRUE)
#option(PORKANOID_SPDLOG_BUNDLED "Use bundled spdlog library" TRUE)

add_library(common INTERFACE)
add_library(PORKANOID::common ALIAS common)
target_compile_options(common
    INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra>
    )

add_subdirectory(dependencies)
add_subdirectory(sources)
