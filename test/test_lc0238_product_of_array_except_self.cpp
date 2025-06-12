/*
 * Time : 2025-06-12 14:21:47
 * URL  :
 * https://leetcode.cn/problems/product-of-array-except-self/description/?envType=problem-list-v2URL_STRenvId=prefix-sum
 */
#include <cstdint>

#include "gtest/gtest.h"
#include "lc0238_product_of_array_except_self.h"

using namespace std;

class TEST_LC0238 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0238_ProductOfArrayExceptSelf *> m_testList;
    void RunTest(vector<int> &nums, vector<int> expect);
};

void TEST_LC0238::SetUp()
{
    m_testList.push_back(new LC0238_ProductOfArrayExceptSelf());
}

void TEST_LC0238::TearDown()
{
    for (LC0238_ProductOfArrayExceptSelf *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0238::RunTest(vector<int> &nums, vector<int> expect)
{
    for (LC0238_ProductOfArrayExceptSelf *inst : m_testList) {
        vector<int> result = inst->productExceptSelf(nums);
        ASSERT_EQ(expect.size(), result.size());
        for (uint32_t i = 0; i < result.size(); i++) {
            EXPECT_EQ(expect[i], result[i]);
        }
    }
}

TEST_F(TEST_LC0238, case1)
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> expect = {24, 12, 8, 6};
    RunTest(nums, expect);
}

TEST_F(TEST_LC0238, case2)
{
    vector<int> nums = {-1, 1, 0, -3, 3};
    vector<int> expect = {0, 0, 9, 0, 0};
    RunTest(nums, expect);
}
