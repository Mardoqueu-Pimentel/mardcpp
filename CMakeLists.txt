cmake_minimum_required(VERSION 3.13)

project(mardcpp VERSION 1.0.0 LANGUAGES CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	add_compile_options (-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_compile_options (-fcolor-diagnostics)
endif ()

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	message("development environment activated")
	set(ENVIRONMENT Env::DEVELOPMENT)
elseif(${CMAKE_BUILD_TYPE} MATCHES "Release")
	message("production environment activated")
	set(ENVIRONMENT Env::PRODUCTION)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(TARGET_MARDCPP ${PROJECT_NAME})
set(TARGET_TEST test)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/*.hpp)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp)


add_library(${TARGET_MARDCPP} ${HEADERS} ${SOURCES})
target_include_directories(${TARGET_MARDCPP}
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${PROJECT_SOURCE_DIR}/lib/random/include
)
set_target_properties(${TARGET_MARDCPP} PROPERTIES
	CXX_STANDARD 20
	POSITION_INDEPENDENT_CODE ON
	PREFIX ""
)

add_executable(${TARGET_TEST} src/app.cpp)
set_target_properties(${TARGET_TEST} PROPERTIES
	CXX_STANDARD 20
)
target_link_libraries(${TARGET_TEST} ${TARGET_MARDCPP})

if (DEFINED ENVIRONMENT)
	target_compile_definitions(${TARGET_MARDCPP} PRIVATE ENVIRONMENT=${ENVIRONMENT})
endif()

if (MSVC)
	target_compile_options(${TARGET_MARDCPP}
		PRIVATE /W4 /WX
	)
else()
	target_compile_options(${TARGET_MARDCPP}
		PRIVATE -Wall -Wextra -pedantic
	)
endif()

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
	target_link_libraries(${TARGET_MARDCPP} OpenMP::OpenMP_CXX)
endif()