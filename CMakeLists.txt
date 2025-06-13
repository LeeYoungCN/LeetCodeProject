cmake_minimum_required(VERSION 3.14)
project(LeetCode)

include(${CMAKE_SOURCE_DIR}/cmake/third_lib_config.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

message(STATUS CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME})

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "CMAKE_BUILD_TYPE Debug" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

if (NOT PROBLEM_PREFIX)
    set(PROBLEM_PREFIX ALL CACHE STRING "PROBLEM_PREFIX ALL" FORCE)
endif()
message(STATUS "PROBLEM_PREFIX: ${PROBLEM_PREFIX}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG_MODE)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")

set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_C_FLAGS_RELEASE " -O3")

add_compile_options("-Wall" "-Wconversion" "-Wextra")

set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)
set(CMAKE_VERBOSE_MAKEFILE          OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(UTILS_LIB_NAME utils)
set(UTILS_LIB_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/utils/inc)
add_subdirectory(utils)

set(LEETCODE_LIB_NAME leetcode)
set(LEETCODE_LIB_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/leetcode/inc)
add_subdirectory(leetcode)

enable_testing()

set(TEST_RUNTIME_NAME leetcode_test)
add_subdirectory(test)
add_dependencies(${TEST_RUNTIME_NAME} ${LEETCODE_LIB_NAME} ${UTILS_LIB_NAME})

install(TARGETS ${TEST_RUNTIME_NAME} ${LEETCODE_LIB_NAME} ${UTILS_LIB_NAME}
        ARCHIVE DESTINATION lib       # 静态库 (.a)
        LIBRARY DESTINATION lib       # 共享库 (.so/.dylib)
        RUNTIME DESTINATION bin       # Windows DLL
        COMPONENT runtime)
