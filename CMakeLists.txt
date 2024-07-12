cmake_minimum_required(VERSION 3.21)
project(Build)
set(CONAN_DISABLE_CHECK_COMPILER TRUE CACHE BOOL "" FORCE )

include(${CMAKE_SOURCE_DIR}/out/build/conan/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(eggo)
add_subdirectory(application)
