/*
 * Time : 2025-07-16 09:26:47
 * URL  :
 * https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-i/description/?envType=daily-question&envId=2025-07-16
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc32xx/lc320x/lc3201_find_the_maximum_length_of_valid_subsequence_i.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3201 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3201_FindTheMaximumLengthOfValidSubsequenceI*> m_testList;
    void RunTest(std::vector<int32_t>& nums, int32_t& expect);
};

void TEST_LC3201::SetUp()
{
    m_testList.push_back(new LC3201_FindTheMaximumLengthOfValidSubsequenceI());
}

void TEST_LC3201::TearDown()
{
    for (LC3201_FindTheMaximumLengthOfValidSubsequenceI* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3201::RunTest(std::vector<int32_t>& nums, int32_t& expect)
{
    for (LC3201_FindTheMaximumLengthOfValidSubsequenceI* inst : m_testList) {
        int32_t result = inst->maximumLength(nums);
        EXPECT_EQ(expect, result) << "nums = " << Vector2String(nums);
    }
}

TEST_F(TEST_LC3201, case1)
{
    std::vector<int32_t> nums = String2VecInt("[1,2,3,4]");
    int32_t expect = 4;
    RunTest(nums, expect);
}

TEST_F(TEST_LC3201, case2)
{
    std::vector<int32_t> nums = String2VecInt("[1,2,1,1,2,1,2]");
    int32_t expect = 6;
    RunTest(nums, expect);
}

TEST_F(TEST_LC3201, case3)
{
    std::vector<int32_t> nums = String2VecInt("[1,3]");
    int32_t expect = 2;
    RunTest(nums, expect);
}
