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
)

set(SOURCES_PATH ${PROJECT_SOURCE_DIR}/src)
set(SOURCES
	${SOURCES_PATH}/mardcpp.cpp
	${SOURCES_PATH}/time.cpp
	${SOURCES_PATH}/utils/util.cpp
	${SOURCES_PATH}/utils/Arguments.cpp
	${SOURCES_PATH}/utils/strings.cpp
	${SOURCES_PATH}/stream/InputStream.cpp
	${SOURCES_PATH}/stream/OutputStream.cpp	
)

set(INC_PATH ${PROJECT_SOURCE_DIR}/include)
set(LIB_RANDOM_INC ${PROJECT_SOURCE_DIR}/lib/random/include)

add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_NAME}
	PUBLIC
		${INC_PATH}
		${LIB_RANDOM_INC}
)

set(TEST_HEADERS
	${HEADERS_PATH}/test.hpp
)

set(TEST_SOURCES
	${SOURCES_PATH}/test.cpp
)

add_executable(${PROJECT_NAME}Test ${TEST_HEADERS} ${TEST_SOURCES})
target_include_directories(${PROJECT_NAME}Test
	PRIVATE
		${INC_PATH}
		${LIB_RANDOM_INC}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME}Test PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME}Test ${PROJECT_NAME})

#set(tool_dest "bin")
#set(include_dest "include/${PROJECT_NAME}-${PROJECT_VERSION}")
#set(lib_dest "lib/${PROJECT_NAME}-${PROJECT_VERSION}")

#add_executable(test test.cpp)

#find_package(OpenMP REQUIRED)
#find_package(Curses REQUIRED)

#include_directories(${CURSES_INCLUDE_DIR})

#target_link_libraries(test PRIVATE OpenMP::OpenMP_CXX ${PROJECT_SOURCE_DIR}/build/lib/libmardcpp.a ${CURSES_LIBRARIES})
