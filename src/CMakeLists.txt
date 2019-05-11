cmake_minimum_required(VERSION 3.13)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(
        ${PROJECT_NAME}
        mardcpp.cpp ${PROJECT_SOURCE_DIR}/include/mardcpp/mardcpp.h
        time.cpp ${PROJECT_SOURCE_DIR}/include/mardcpp/time.h
        utils/util.cpp ${PROJECT_SOURCE_DIR}/include/mardcpp/utils/util.h
        ${PROJECT_SOURCE_DIR}/include/mardcpp/collections/Collections.h
        ${PROJECT_SOURCE_DIR}/include/mardcpp/collections/LinkedList.h
        ../include/mardcpp/utils/ios.h)
