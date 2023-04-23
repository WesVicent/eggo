cmake_minimum_required(VERSION 3.21)
project(eggoproj)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(eggo)
add_subdirectory(application)
