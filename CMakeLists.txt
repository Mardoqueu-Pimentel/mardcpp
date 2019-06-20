cmake_minimum_required(VERSION 3.13)

project(mardcpp VERSION 1.0.0 LANGUAGES CXX)

if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-W -Wall -Werror -Wextra -Wpedantic -Wno-unused-parameter)
endif()

add_subdirectory(src)

#set(TARGET_LIB_MARDCPP ${PROJECT_NAME})

#target_include_directories(${TARGET_LIB_MARDCPP} PUBLIC include)
#target_include_directories(${TARGET_LIB_MARDCPP} PRIVATE src)

set(tool_dest "bin")
set(include_dest "include/${PROJECT_NAME}-${PROJECT_VERSION}")