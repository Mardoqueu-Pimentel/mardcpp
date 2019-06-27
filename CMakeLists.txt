cmake_minimum_required(VERSION 3.13)

project(mardcpp VERSION 1.0.0 LANGUAGES CXX)

if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall)
endif()

add_subdirectory(src)
