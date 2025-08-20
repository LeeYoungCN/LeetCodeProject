/*
 * Time : 2025-07-13 19:56:45
 * URL  : https://leetcode.cn/problems/single-element-in-a-sorted-array/description/
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc05xx/lc054x/lc0540_single_element_in_a_sorted_array.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0540 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0540_SingleElementInASortedArray*> m_testList;
    void RunTest(std::vector<int32_t>& nums, int32_t& expect);
};

void TEST_LC0540::SetUp()
{
    m_testList.push_back(new LC0540_SingleElementInASortedArray());
}

void TEST_LC0540::TearDown()
{
    for (LC0540_SingleElementInASortedArray* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0540::RunTest(std::vector<int32_t>& nums, int32_t& expect)
{
    for (LC0540_SingleElementInASortedArray* inst : m_testList) {
        int32_t result = inst->singleNonDuplicate(nums);
        EXPECT_EQ(expect, result) << Vector2String(nums);
    }
}

TEST_F(TEST_LC0540, case1)
{
    std::vector<int32_t> nums = CreateIntVector("[1,1,2,3,3,4,4,8,8]");
    int32_t expect = 2;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0540, case2)
{
    std::vector<int32_t> nums = CreateIntVector("[3,3,7,7,10,11,11]");
    int32_t expect = 10;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0540, case3)
{
    std::vector<int32_t> nums = CreateIntVector("[1,2,2,3,3]");
    int32_t expect = 1;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0540, case4)
{
    std::vector<int32_t> nums = CreateIntVector("[1,1,2,2,3]");
    int32_t expect = 3;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0540, case5)
{
    std::vector<int32_t> nums = CreateIntVector("[3]");
    int32_t expect = 3;
    RunTest(nums, expect);
}

TEST_F(TEST_LC0540, case6)
{
    std::vector<int32_t> nums = CreateIntVector("[1,1,2,3,3]");
    int32_t expect = 2;
    RunTest(nums, expect);
}
