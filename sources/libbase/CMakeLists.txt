project(libbase
    LANGUAGES CXX
    VERSION ${PORKANOID_VERSION}
    )

add_library(${PROJECT_NAME} STATIC)
add_library(PORKANOID::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME porkanoid-base
    )
target_link_libraries(${PROJECT_NAME}
    INTERFACE
    #spdlog::spdlog
    #fmt::fmt
    SFML::Graphics
    SFML::Window
    SFML::System
    PORKANOID::common
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/include"
    #$<TARGET_PROPERTY:spdlog::spdlog,INTERFACE_INCLUDE_DIRECTORIES>
    #$<TARGET_PROPERTY:fmt::fmt,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:SFML::Graphics,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:SFML::Window,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:SFML::System,INTERFACE_INCLUDE_DIRECTORIES>
    )

set(HEADER_FILES
    include/pd/context.hpp
    include/pd/app.hpp
    include/pd/stdpaths.hpp
    )
set(SOURCE_FILES
    src/pd/context.cpp
    src/pd/app.cpp
    src/pd/stdpaths.cpp
    )

target_sources(${PROJECT_NAME}
    PRIVATE ${SOURCE_FILES}
    PUBLIC ${HEADER_FILES}
    )

if(PORKANOID_BUILD_UT)
    add_subdirectory(ut)
endif()

