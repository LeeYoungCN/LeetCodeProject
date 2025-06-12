add_executable(${TEST_RUNTIME_NAME})

if (PROBLEM_PREFIX STREQUAL "ALL")
    aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
else()
    file(GLOB SRC_LIST "test_${PROBLEM_PREFIX}*.cpp" main.cpp)
endif()

target_sources(${TEST_RUNTIME_NAME} PRIVATE ${SRC_LIST})

add_dependencies(${TEST_RUNTIME_NAME} ${LEETCODE_LIB_NAME})

target_include_directories(${TEST_RUNTIME_NAME} PRIVATE
    ${GOOGLE_TEST_INCLUDE_PATH}
    ${MOCKCPP_INCLUDE_PATH}
    ${LEETCODE_LIB_INCLUDE_PATH}
    ${UTILS_LIB_INCLUDE_PATH}
)

target_link_directories(${TEST_RUNTIME_NAME} PRIVATE
    ${GOOGLE_TEST_LIBRARY_PATH}
    ${MOCKCPP_LIBRARY_PATH}
)

target_link_libraries(${TEST_RUNTIME_NAME} ${LEETCODE_LIB_NAME} ${UTILS_LIB_NAME} gtest mockcpp)
