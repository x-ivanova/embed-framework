cmake_minimum_required(VERSION 2.8)
project(code)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1y -pedantic -Wextra")

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

find_package(Boost 1.52 COMPONENTS system thread REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

add_executable(main source/main.cpp)
target_link_libraries(main ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})