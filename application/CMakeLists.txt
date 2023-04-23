cmake_minimum_required(VERSION 3.21)
project(application)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EGGO_DIR "${CMAKE_SOURCE_DIR}/eggo")

file(GLOB headers  
"${EGGO_DIR}/src/**/*.h"
"${EGGO_DIR}/src/**/**/*.h")
					
file(GLOB sources "${CMAKE_SOURCE_DIR}/application/src/main.cpp")

add_executable(application ${sources})

# Create source groups for fancy IDE structure
source_group(TREE "${EGGO_DIR}/src" PREFIX "Header Files" FILES ${headers})

target_link_libraries(application PUBLIC eggo)

target_include_directories(application PUBLIC ${CMAKE_SOURCE_DIR}/eggo/src)
