cmake_minimum_required(VERSION 3.0)

project(game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(
    SOURCES
    src/main.cpp
)

set(
    INCLUDES
    libs/SFML/include
)

set(
    LIBRARIES
    sfml-window
    sfml-graphics
    sfml-system
)


add_subdirectory(libs/SFML)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

add_custom_command(
    TARGET ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)