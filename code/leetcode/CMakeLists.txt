add_library(${LEETCODE_LIB_NAME} SHARED)

set_target_properties(${LEETCODE_LIB_NAME} PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS ON  # 自动导出所有符号
)

if (CMAKE_PROBLEM_PREFIX STREQUAL "all")
    aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
else()
    file(GLOB SRC_LIST "src/${CMAKE_PROBLEM_PREFIX}*.cpp")
endif()

target_sources(${LEETCODE_LIB_NAME} PRIVATE ${SRC_LIST})
target_include_directories(${LEETCODE_LIB_NAME} PRIVATE inc ${UTILS_LIB_INCLUDE_PATH})
target_link_libraries(${LEETCODE_LIB_NAME} PRIVATE ${UTILS_LIB_NAME})
