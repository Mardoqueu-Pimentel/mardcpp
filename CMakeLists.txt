cmake_minimum_required(VERSION 3.13)

project(mardcpp VERSION 1.0.0 LANGUAGES CXX)

if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
