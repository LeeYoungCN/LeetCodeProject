set(UTILS_LIB_NAME utils)
set(UTILS_LIB_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/utils/inc)
add_subdirectory(utils)

set(LEETCODE_LIB_NAME leetcode)
set(LEETCODE_LIB_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/leetcode/inc)
add_subdirectory(leetcode)

set(TEST_RUNTIME_NAME leetcode_test)
add_subdirectory(test)
add_dependencies(${TEST_RUNTIME_NAME} ${LEETCODE_LIB_NAME} ${UTILS_LIB_NAME})

install(TARGETS ${TEST_RUNTIME_NAME} ${LEETCODE_LIB_NAME} ${UTILS_LIB_NAME}
        ARCHIVE DESTINATION lib  # 静态库 (.a)
        LIBRARY DESTINATION lib  # 共享库 (.so/.dylib)
        RUNTIME DESTINATION bin  # Windows DLL
        COMPONENT all)

install(TARGETS ${TEST_RUNTIME_NAME} COMPONENT leetcode_test)
install(TARGETS ${LEETCODE_LIB_NAME} COMPONENT leetcode)
install(TARGETS ${UTILS_LIB_NAME}    COMPONENT utils)
