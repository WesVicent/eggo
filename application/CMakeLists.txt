cmake_minimum_required(VERSION 3.21)
project(application)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EGGO_DIR "${CMAKE_SOURCE_DIR}/eggo")

#file(GLOB headers"${EGGO_DIR}/include/eggo.h")
file(GLOB sources "${CMAKE_SOURCE_DIR}/application/src/main.cpp")

add_executable(application ${sources})

target_link_libraries(application PRIVATE eggo)
target_link_libraries(eggo INTERFACE "${CONAN_LIBS}")

#target_include_directories(application PRIVATE ${headers})
