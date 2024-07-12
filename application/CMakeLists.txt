cmake_minimum_required(VERSION 3.21)
project(application)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EGGO_DIR "${CMAKE_SOURCE_DIR}/eggo")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB headers"${EGGO_DIR}/include/eggo.h")
file(GLOB sources "${CMAKE_SOURCE_DIR}/application/src/main.cpp")

add_executable(application ${sources})
target_include_directories(application PUBLIC ${headers})
target_compile_features(application PUBLIC cxx_std_17)

source_group(TREE "${LIB_DIR}/include" PREFIX "Header Files" FILES ${headers})
target_include_directories(application PRIVATE "${LIB_DIR}/include")

target_link_libraries(application eggo)

add_custom_command(
        TARGET application POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/application/resource
        ${CMAKE_CURRENT_BINARY_DIR}/../resource
)