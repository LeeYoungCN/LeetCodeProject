add_library(${LEETCODE_LIB_NAME} SHARED)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
target_sources(${LEETCODE_LIB_NAME} PRIVATE ${SRC_LIST})
target_include_directories(${LEETCODE_LIB_NAME} PRIVATE inc)
target_include_directories(${LEETCODE_LIB_NAME} PRIVATE ${UTILS_LIB_INCLUDE_PATH})

target_link_libraries(${LEETCODE_LIB_NAME} ${UTILS_LIB_NAME})
