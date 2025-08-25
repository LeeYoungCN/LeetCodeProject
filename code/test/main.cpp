#include <cstdio>

#include "gtest/gtest.h"
#include "leetcode_utils/leetcode_utils_logging.hpp"

int main(int argc, char *argv[])
{
    leetcode_utils::SetDebugLogLevel(leetcode_utils::LogLevel::DEBUG);
    printf("Running main() from: %s.\n", __FILE__);
    printf("Build time: %s.\n", __TIME__);
    testing::InitGoogleTest(&argc, argv);
    auto rst = RUN_ALL_TESTS();
    return rst;
}
