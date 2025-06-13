# 启用测试
enable_testing()

# 设置测试日志的基础目录
set(CTEST_BINARY_DIRECTORY "${CMAKE_SOURCE_DIR}/out/Testing")

# 设置 XML 测试报告的输出路径
set(CTEST_TEST_OUTPUT_DIRECTORY "${CTEST_BINARY_DIRECTORY}/TestResults")

# 可选：设置内存检查报告路径
set(CTEST_MEMORYCHECK_COMMAND_OPTIONS "--log-file=${CTEST_BINARY_DIRECTORY}/MemCheck.log")

# 可选：设置覆盖率报告路径
set(CTEST_COVERAGE_COMMAND_OPTIONS "--output-dir=${CTEST_BINARY_DIRECTORY}/Coverage")