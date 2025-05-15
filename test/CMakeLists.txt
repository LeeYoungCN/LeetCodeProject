add_executable(${RUNTIME_NAME})
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
target_sources(${RUNTIME_NAME} PRIVATE ${SRC_LIST})

add_dependencies(${RUNTIME_NAME} ${LIB_NAME})

target_include_directories(${RUNTIME_NAME} PRIVATE
    ${GOOGLE_TEST_INCLUDE_PATH}
    ${MOCKCPP_INCLUDE_PATH}
    ${LIB_INCLUDE_PATH}
)

target_link_directories(${RUNTIME_NAME} PRIVATE
    ${GOOGLE_TEST_LIBRARY_PATH}
    ${MOCKCPP_LIBRARY_PATH}
)

target_link_libraries(${RUNTIME_NAME} ${LIB_NAME} gtest mockcpp)
