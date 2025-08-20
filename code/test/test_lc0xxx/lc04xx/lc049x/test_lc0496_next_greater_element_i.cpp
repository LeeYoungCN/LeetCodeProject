/*
 * Time : 2025-07-13 22:21:47
 * URL  : https://leetcode.cn/problems/next-greater-element-i/description/?envType=problem-list-v2&envId=monotonic-stack
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc04xx/lc049x/lc0496_next_greater_element_i.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0496 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0496_NextGreaterElementI*> m_testList;
    void RunTest(std::vector<int32_t>& nums1, std::vector<int32_t>& nums2, std::vector<int32_t>& expect);
};

void TEST_LC0496::SetUp()
{
    m_testList.push_back(new LC0496_NextGreaterElementI());
}

void TEST_LC0496::TearDown()
{
    for (LC0496_NextGreaterElementI* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0496::RunTest(std::vector<int32_t>& nums1, std::vector<int32_t>& nums2, std::vector<int32_t>& expect)
{
    for (LC0496_NextGreaterElementI* inst : m_testList) {
        std::vector<int32_t> result = inst->nextGreaterElement(nums1, nums2);

        EXPECT_EQ(expect, result) << "nums1 = " << Vector2String(nums1) << endl << "nums2 = " << Vector2String(nums2);
    }
}

TEST_F(TEST_LC0496, case1)
{
    std::vector<int32_t> nums1 = CreateIntVector("[4,1,2]");
    std::vector<int32_t> nums2 = CreateIntVector("[1,3,4,2]");
    std::vector<int32_t> expect = CreateIntVector("[-1,3,-1]");
    RunTest(nums1, nums2, expect);
}

TEST_F(TEST_LC0496, case2)
{
    std::vector<int32_t> nums1 = CreateIntVector("[2,4]");
    std::vector<int32_t> nums2 = CreateIntVector("[1,2,3,4]");
    std::vector<int32_t> expect = CreateIntVector("[3,-1]");
    RunTest(nums1, nums2, expect);
}
