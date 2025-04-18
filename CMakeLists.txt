cmake_minimum_required(VERSION 3.14)
project(LeetCode)
message(STATUS CMAKE_SYSTEM_NAME:${CMAKE_SYSTEM_NAME})
include(${CMAKE_SOURCE_DIR}/cmake/third_lib_config.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/compiler_${CMAKE_SYSTEM_NAME}.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "CMAKE_BUILD_TYPE Debug" FORCE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -O0")
set(TARGET_NAME LeetCodePractice)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
enable_testing()

add_executable(${TARGET_NAME})
add_subdirectory(src)
target_include_directories(${TARGET_NAME} PRIVATE
    ${GOOGLE_TEST_INCLUDE_PATH}
    ${MOCKCPP_INCLUDE_PATH}
)
target_link_directories(${TARGET_NAME} PRIVATE
    ${GOOGLE_TEST_LIBRARY_PATH}
    ${MOCKCPP_LIBRARY_PATH}
)
target_link_libraries(${TARGET_NAME} gtest mockcpp)
