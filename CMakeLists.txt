cmake_minimum_required(VERSION 3.14)
project(LeetCode)
message(STATUS CMAKE_SYSTEM_NAME:${CMAKE_SYSTEM_NAME})

include(${CMAKE_SOURCE_DIR}/cmake/third_lib_config.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "CMAKE_BUILD_TYPE Debug" FORCE)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -O0")
set(CMAKE_C_FLAGS_DEBUG "-g -Wall -O0")

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O3")
set(CMAKE_C_FLAGS_RELEASE "-Wall -O3")

set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)
set(CMAKE_VERBOSE_MAKEFILE          OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(RUNTIME_NAME leetcode_test)
set(LIB_NAME leetcode)
set(LIB_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/leetcode/include)

add_subdirectory(leetcode)
add_subdirectory(test)

install(TARGETS ${RUNTIME_NAME} COMPONENT runtime)
install(TARGETS ${LIB_NAME})
