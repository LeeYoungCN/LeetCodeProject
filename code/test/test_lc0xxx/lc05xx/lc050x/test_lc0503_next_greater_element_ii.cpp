/*
 * Time : 2025-07-14 10:37:14
 * URL  : https://leetcode.cn/problems/next-greater-element-ii/?envType=problem-list-v2&envId=monotonic-stack
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc05xx/lc050x/lc0503_next_greater_element_ii.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0503 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0503_NextGreaterElementII*> m_testList;
    void RunTest(std::vector<int32_t>& nums, std::vector<int32_t>& expect);
};

void TEST_LC0503::SetUp()
{
    m_testList.push_back(new LC0503_NextGreaterElementII());
}

void TEST_LC0503::TearDown()
{
    for (LC0503_NextGreaterElementII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0503::RunTest(std::vector<int32_t>& nums, std::vector<int32_t>& expect)
{
    for (LC0503_NextGreaterElementII* inst : m_testList) {
        std::vector<int32_t> result = inst->nextGreaterElements(nums);
        EXPECT_EQ(expect, result) << Vector2String(nums);
    }
}

TEST_F(TEST_LC0503, case1)
{
    std::vector<int32_t> nums = CreateIntVector("[1,2,1]");
    std::vector<int32_t> expect = CreateIntVector("[2,-1,2]");
    RunTest(nums, expect);
}

TEST_F(TEST_LC0503, case2)
{
    std::vector<int32_t> nums = CreateIntVector("[1,2,3,4,3]");
    std::vector<int32_t> expect = CreateIntVector("[2,3,4,-1,4]");
    RunTest(nums, expect);
}

TEST_F(TEST_LC0503, case3)
{
    std::vector<int32_t> nums = CreateIntVector("[5,4,3,2,1]");
    std::vector<int32_t> expect = CreateIntVector("[-1,5,5,5,5]");
    RunTest(nums, expect);
}
