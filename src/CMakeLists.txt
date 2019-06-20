cmake_minimum_required(VERSION 3.13)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/lib/random/include)

add_library(${PROJECT_NAME}
	mardcpp.cpp
	${PROJECT_SOURCE_DIR}/include/mardcpp/mardcpp
	time.cpp
	../include/mardcpp/utils/time.h
	utils/util.cpp
	${PROJECT_SOURCE_DIR}/include/mardcpp/utils/util.h
	${PROJECT_SOURCE_DIR}/include/mardcpp/collections/Collections.h
	${PROJECT_SOURCE_DIR}/include/mardcpp/collections/LinkedList.h
	../include/mardcpp/utils/Kwargs
	../include/mardcpp/std/Pair
	../include/mardcpp/std/String
	../include/mardcpp/std/UnorderedMap
	../include/mardcpp/std/Vector
	../include/mardcpp/utils/strings
	../include/mardcpp/std/UnorderedSet
	utils/Kwargs.cpp utils/strings.cpp
	../include/mardcpp/stream/OutputStream
	../include/mardcpp/stream/InputStream
	stream/InputStream.cpp
	stream/OutputStream.cpp
	../include/mardcpp/std/Map
)

add_executable(test test.cpp)

find_package(OpenMP REQUIRED)
find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(test PRIVATE OpenMP::OpenMP_CXX ${PROJECT_SOURCE_DIR}/build/lib/libmardcpp.a ${CURSES_LIBRARIES})
