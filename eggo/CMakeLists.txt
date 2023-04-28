cmake_minimum_required(VERSION 3.21)
project(eggo VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJ_DIR "${CMAKE_SOURCE_DIR}/eggo")

set(DEBUG_TYPE "Debug")
set(RELEASE_TYPE "Release")

# Debug as default build
if(NOT DEFINED CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE ${DEBUG_TYPE})
endif()

if(CMAKE_GENERATOR  MATCHES "Visual Studio")

	file(GLOB sources
	"${PROJ_DIR}/src/*.cpp"
	"${PROJ_DIR}/src/**/*.cpp"
	"${PROJ_DIR}/src/**/**/*.cpp")

	file(GLOB headers
	"${PROJ_DIR}/include/*.h"
	"${PROJ_DIR}/include/**/*.h"
	"${PROJ_DIR}/include/**/**/*.h")

	# Flags to VS  use this CMake roles to IDE build.
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DCMAKE_BUILD_TYPE=Release")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DCMAKE_BUILD_TYPE=Debug")

	if(CMAKE_BUILD_TYPE STREQUAL ${DEBUG_TYPE}) # ---------------------------------------------------- Debug
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DVSDEBUG")
		#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")

		add_library(eggo STATIC ${sources})
	endif()

	if(CMAKE_BUILD_TYPE STREQUAL ${RELEASE_TYPE}) # ------------------------------------------------ Release
		set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
		add_library(eggo SHARED ${sources})
	endif()

		target_sources(eggo PUBLIC ${headers}) # ------------------------------------------------------------------ Common

		# Create source groups for fancy IDE structure
		source_group(TREE "${PROJ_DIR}/include" PREFIX "Header Files" FILES ${headers})
		source_group(TREE "${PROJ_DIR}/src" PREFIX "Source Files" FILES ${sources})

		target_include_directories(eggo PUBLIC ${PROJ_DIR}/include)

		target_link_libraries(eggo PRIVATE ${CONAN_LIBS})

else() # Is not trying to  generating a Visual Studio solution.
	message("Message: Eggo v-${CMAKE_PROJECT_VERSION}")
	message("For now Eggo has only Win Visual Studio as official CMake build.")
	message("Since the project has not been built on other platform, its code was not reviewed any other platform yet.")
endif()