project(libgame
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
    OUTPUT_NAME porkanoid-game
    )
target_link_libraries(${PROJECT_NAME}
    INTERFACE
    #spdlog::spdlog
    #fmt::fmt
    PORKANOID::libbase
    PORKANOID::common
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/include"
    #$<TARGET_PROPERTY:spdlog::spdlog,INTERFACE_INCLUDE_DIRECTORIES>
    #$<TARGET_PROPERTY:fmt::fmt,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:PORKANOID::libbase,INTERFACE_INCLUDE_DIRECTORIES>
    )

set(HEADER_FILES
    include/pd/game/app.hpp
    )
set(SOURCE_FILES
    src/pd/game/app.cpp
    )

target_sources(${PROJECT_NAME}
    PRIVATE ${SOURCE_FILES}
    PUBLIC ${HEADER_FILES}
    )

if(PORKANOID_BUILD_UT)
    add_subdirectory(ut)
endif()

