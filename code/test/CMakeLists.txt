add_executable(${TEST_RUNTIME_NAME})

set_target_properties(${TEST_RUNTIME_NAME} PROPERTIES
    COMPILE_PDB_NAME_DEBUG "${TEST_RUNTIME_NAME}_debug"
    COMPILE_PDB_NAME_RELEASE "${TEST_RUNTIME_NAME}_release"
)

if (PROBLEM_PREFIX STREQUAL "all")
    aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
else()
    file(GLOB SRC_LIST "test_${PROBLEM_PREFIX}*.cpp" main.cpp)
endif()

target_sources(${TEST_RUNTIME_NAME} PRIVATE ${SRC_LIST})

add_dependencies(${TEST_RUNTIME_NAME} ${LEETCODE_LIB_NAME})

target_include_directories(${TEST_RUNTIME_NAME} PRIVATE
    ${LEETCODE_LIB_INCLUDE_PATH}
    ${UTILS_LIB_INCLUDE_PATH}
)

find_package(GTest REQUIRED)
target_link_libraries(${TEST_RUNTIME_NAME} ${LEETCODE_LIB_NAME} ${UTILS_LIB_NAME} GTest::GTest)

# 添加ctest测试
add_test(NAME TEST_ALL COMMAND ${TEST_RUNTIME_NAME})
set_tests_properties(TEST_ALL PROPERTIES TIMEOUT 1)

if (${PROBLEM_PREFIX} STREQUAL "all")
    file(GLOB TEST_FILE_LIST "test_*.cpp")
    foreach(FILE_PATH ${TEST_FILE_LIST})
        get_filename_component(FILE_NAME ${FILE_PATH} NAME)
        string(REGEX MATCH "^test_lc[0-9]+" _ "${FILE_NAME}")
        set(TEST_CASE  ${CMAKE_MATCH_0})
        string(TOUPPER "${CMAKE_MATCH_0}" TEST_CASE)
        # 增加单个题目的测试用例
        add_test(NAME ${TEST_CASE} COMMAND ${TEST_RUNTIME_NAME} --gtest_filter=${TEST_CASE}.*)
        set_tests_properties(${TEST_CASE} PROPERTIES TIMEOUT 1)
    endforeach()
endif()
