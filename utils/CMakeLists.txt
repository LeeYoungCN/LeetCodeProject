add_library(${UTILS_LIB_NAME} SHARED)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
target_sources(${UTILS_LIB_NAME} PRIVATE ${SRC_LIST})
target_include_directories(${UTILS_LIB_NAME} PRIVATE inc)
