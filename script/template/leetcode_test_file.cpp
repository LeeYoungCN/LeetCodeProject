// URL_STR
#include <vector>
#include "gtest/gtest.h"
#include "HEAD_FILE_NAME"

using namespace std;

class TEST_CLASSNAME : public testing::Test {
    protected:
        CLASS_NAME m_test;
        void RunTest(vector<int>& nums, int expectResult);
};
    
void TEST_CLASSNAME::RunTest(vector<int>& nums, int expectResult)
{
    EXPECT_EQ(expectResult, m_test.CLASS_FUNC);
}

TEST_F(TEST_CLASSNAME, case1)
{
    vector<int> nums = {1, 2, 3, 4};
    RunTest(nums, 0);
}

