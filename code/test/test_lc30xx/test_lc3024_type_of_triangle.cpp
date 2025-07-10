// https://leetcode.cn/problems/type-of-triangle/?envType=daily-questionURL_STRenvId=2025-05-19
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc30xx/lc3024_type_of_triangle.h"

using namespace std;

class TEST_LC3024 : public testing::Test {
protected:
    LC3024_TypeOfTriangle m_test;
    void RunTest(vector<int> &nums, const char *expectResult);
};

void TEST_LC3024::RunTest(vector<int> &nums, const char *expectResult)
{
    string result = m_test.triangleType(nums);
    EXPECT_STREQ(expectResult, result.c_str());
}

TEST_F(TEST_LC3024, case1)
{
    vector<int> nums = {3, 3, 3};
    RunTest(nums, "equilateral");
}

TEST_F(TEST_LC3024, case2)
{
    vector<int> nums = {3, 4, 5};
    RunTest(nums, "scalene");
}

TEST_F(TEST_LC3024, case3)
{
    vector<int> nums = {3, 4, 3};
    RunTest(nums, "isosceles");
}

TEST_F(TEST_LC3024, case4)
{
    vector<int> nums = {3, 4, 7};
    RunTest(nums, "none");
}

TEST_F(TEST_LC3024, case5)
{
    vector<int> nums = {4, 4, 8};
    RunTest(nums, "none");
}
