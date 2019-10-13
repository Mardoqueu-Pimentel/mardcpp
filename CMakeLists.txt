cmake_minimum_required(VERSION 3.13)

project(mardcpp VERSION 1.0.0 LANGUAGES CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	add_compile_options (-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_compile_options (-fcolor-diagnostics)
endif ()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(TARGET_MARDCPP ${PROJECT_NAME})
set(HEADERS_PATH ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME})
set(HEADERS
	${HEADERS_PATH}/collections/Collections.hpp
	${HEADERS_PATH}/collections/LinkedList.hpp
	${HEADERS_PATH}/std/Pair.hpp
	${HEADERS_PATH}/std/String.hpp
	${HEADERS_PATH}/std/Map.hpp
	${HEADERS_PATH}/std/UnorderedMap.hpp
	${HEADERS_PATH}/std/Vector.hpp
	${HEADERS_PATH}/std/UnorderedSet.hpp
	${HEADERS_PATH}/mardcpp.hpp
	${HEADERS_PATH}/utils/time.hpp
	${HEADERS_PATH}/utils/util.hpp
	${HEADERS_PATH}/utils/Arguments.hpp
	${HEADERS_PATH}/utils/strings.hpp
	${HEADERS_PATH}/stream/InputStream.hpp
	${HEADERS_PATH}/stream/OutputStream.hpp
	${HEADERS_PATH}/utils/Env.hpp
	${HEADERS_PATH}/utils/hash.hpp
	${HEADERS_PATH}/std/Array.hpp
	${HEADERS_PATH}/utils/Logger.hpp
	${HEADERS_PATH}/std/List.hpp

)
set(SOURCES_PATH ${PROJECT_SOURCE_DIR}/src)
set(SOURCES
	${SOURCES_PATH}/time.cpp
	${SOURCES_PATH}/utils/util.cpp
	${SOURCES_PATH}/utils/Arguments.cpp
	${SOURCES_PATH}/utils/strings.cpp
	${SOURCES_PATH}/stream/InputStream.cpp
	${SOURCES_PATH}/stream/OutputStream.cpp
	${SOURCES_PATH}/utils/hash.cpp

)
add_library(${TARGET_MARDCPP} ${HEADERS} ${SOURCES})
target_include_directories(${TARGET_MARDCPP}
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${PROJECT_SOURCE_DIR}/lib/random/include
)

set_target_properties(${TARGET_MARDCPP} PROPERTIES
	CXX_STANDARD 17
	POSITION_INDEPENDENT_CODE ON
	PREFIX ""
)

set(TARGET_MARDCPPTEST mardcpptest)
add_executable(${TARGET_MARDCPPTEST} src/app.cpp)
set_target_properties(${TARGET_MARDCPPTEST} PROPERTIES
	CXX_STANDARD 17
)
target_link_libraries(${TARGET_MARDCPPTEST} ${TARGET_MARDCPP})

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	message("development environment activated")
	set(ENVIRONMENT Env::DEVELOPMENT)
elseif(${CMAKE_BUILD_TYPE} MATCHES "Release")
	message("production environment activated")
	set(ENVIRONMENT Env::PRODUCTION)
endif()

if (DEFINED ENVIRONMENT)
	target_compile_definitions(${TARGET_MARDCPP} PRIVATE ENVIRONMENT=${ENVIRONMENT})
	target_compile_definitions(${TARGET_MARDCPPTEST} PRIVATE ENVIRONMENT=${ENVIRONMENT})
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