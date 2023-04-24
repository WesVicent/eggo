cmake_minimum_required(VERSION 3.21)
project(eggo VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJ_DIR "${CMAKE_SOURCE_DIR}/eggo")

file(GLOB sources
"${PROJ_DIR}/src/*.cpp"
"${PROJ_DIR}/src/**/*.cpp"
"${PROJ_DIR}/src/**/**/*.cpp")

file(GLOB headers
"${PROJ_DIR}/include/*.h"
"${PROJ_DIR}/include/**/*.h"
"${PROJ_DIR}/include/**/**/*.h")

#[[
	When the project is running in VS (.sln) the "current_path" is ./build (.sln path)
	instead of ./build/bin, path where eggo.exe file are.
	BUILD_TYPE_CMDEBUG setting to run .exe from ./build/bin (maybe to attatch in different IDEs/process).
	BUILD_TYPE_VSDEBUG is the default debug build seting.
#]]
option(BUILD_TYPE_CMDEBUG "Flag to configure paths to execute the .exe from ./build/bin" OFF)

if(BUILD_TYPE_CMDEBUG)
	message("EGGO - Setting up to run .exe from ./build/bin")
	add_definitions(-DBUILD_TYPE_CMDEBUG)
else(BUILD_TYPE_CMDEBUG)
	message("EGGO - Setting up to run .exe from ./build (VS)")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DVSDEBUG")
endif(BUILD_TYPE_CMDEBUG)

add_library(eggo ${sources})

target_compile_definitions(eggo PRIVATE EGGO_PRIVATE)

target_sources(eggo PUBLIC ${headers})

# Create source groups for fancy IDE structure
source_group(TREE "${PROJ_DIR}/include" PREFIX "Header Files" FILES ${headers})
source_group(TREE "${PROJ_DIR}/src" PREFIX "Source Files" FILES ${sources})

target_include_directories(eggo PUBLIC ${PROJ_DIR}/include)

target_link_libraries(eggo PRIVATE "${CONAN_LIBS}")
