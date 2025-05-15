add_library(${LIB_NAME} SHARED)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
target_sources(${LIB_NAME} PRIVATE ${SRC_LIST})
target_include_directories(${LIB_NAME} PRIVATE ${LIB_INCLUDE_PATH})
