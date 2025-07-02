if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # 启用RPATH设置
    set(CMAKE_SKIP_BUILD_RPATH FALSE)  # 不跳过构建时的RPATH
    set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)  # 构建时使用默认RPATH
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)  # 使用链接路径作为RPATH的一部分

    # 设置安装后的RPATH（指向动态库所在目录）
    if(UNIX)
        # 对于UNIX系统（Linux/macOS）
        set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")  # 假设库安装在bin目录的上一级的lib目录
        # 也可以添加绝对路径，例如：
        # set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
    endif()
endif()

set(UTILS_LIB_NAME leetcode_utils)
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
