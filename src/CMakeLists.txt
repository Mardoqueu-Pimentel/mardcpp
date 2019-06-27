set(HEADERS_PATH ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME})
set(HEADERS
	${HEADERS_PATH}/collections/Collections.h
	${HEADERS_PATH}/collections/LinkedList.h
	${HEADERS_PATH}/std/Pair
	${HEADERS_PATH}/std/String
	${HEADERS_PATH}/std/Map
	${HEADERS_PATH}/std/UnorderedMap
	${HEADERS_PATH}/std/Vector
	${HEADERS_PATH}/std/UnorderedSet
	${HEADERS_PATH}/mardcpp
	${HEADERS_PATH}/utils/time.h
	${HEADERS_PATH}/utils/util.h
	${HEADERS_PATH}/utils/Arguments
	${HEADERS_PATH}/utils/strings	
	${HEADERS_PATH}/stream/InputStream
	${HEADERS_PATH}/stream/OutputStream
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

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

#set(tool_dest "bin")
#set(include_dest "include/${PROJECT_NAME}-${PROJECT_VERSION}")
#set(lib_dest "lib/${PROJECT_NAME}-${PROJECT_VERSION}")

#add_executable(test test.cpp)

#find_package(OpenMP REQUIRED)
#find_package(Curses REQUIRED)

#include_directories(${CURSES_INCLUDE_DIR})

#target_link_libraries(test PRIVATE OpenMP::OpenMP_CXX ${PROJECT_SOURCE_DIR}/build/lib/libmardcpp.a ${CURSES_LIBRARIES})
