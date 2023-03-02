aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
target_sources(${TARGET_NAME} PRIVATE ${SRC_LIST})
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
