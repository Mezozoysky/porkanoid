project(game
    LANGUAGES CXX)

if (${CMAKE_SYSTEM_NAME} MATCHES "Android")
    message(STATUS "================================== ANDROID APP")
    add_library(${PROJECT_NAME} SHARED)
    add_library(PORKANOID::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
else()
    add_executable(${PROJECT_NAME})
    add_executable(PORKANOID::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
endif()
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED TRUE
    OUTPUT_NAME porkanoid
    )
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    PORKANOID::libgame
    PORKANOID::common
    )
target_include_directories(${PROJECT_NAME}
    PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}"
    )


set(SOURCE_FILES
    main.cpp
    )

target_sources(${PROJECT_NAME}
    PRIVATE
    ${SOURCE_FILES}
    )

# config file for developing
# set(LOG_LEVEL "debug")
# set(LOG_FILE_NAME "PORKANOID.log")
# set(LOG_FILE_TRUNCATE "true")
# set(LOG_STDOUT_COLORS "true")
# set(PATH_TO_ASSETS "${CMAKE_CURRENT_LIST_DIR}/assets/")
# configure_file(porkanoid.xml ${PROJECT_BINARY_DIR}/porkanoid.xml)

#[[
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Copying asset into build derectory.."
        #COMMAND ${CMAKE_COMMAND} -E copy_directory assets ${PROJECT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy config.xml ${PROJECT_BINARY_DIR}/config.xml
)
]]

