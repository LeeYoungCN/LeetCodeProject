add_library(${UTILS_LIB_NAME} SHARED)

set_target_properties(${UTILS_LIB_NAME} PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS ON  # 自动导出所有符号
)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
target_sources(${UTILS_LIB_NAME} PRIVATE ${SRC_LIST})
target_include_directories(${UTILS_LIB_NAME} PRIVATE inc)
