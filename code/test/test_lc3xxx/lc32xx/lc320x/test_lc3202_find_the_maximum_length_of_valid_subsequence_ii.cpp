/*
 * Time : 2025-07-17 15:26:19
 * URL  :
 * https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-ii/description/?envType=daily-question&envId=2025-07-17
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc32xx/lc320x/lc3202_find_the_maximum_length_of_valid_subsequence_ii.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3202 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3202_FindTheMaximumLengthOfValidSubsequenceII*> m_testList;
    void RunTest(std::vector<int32_t>& nums, int32_t k, int32_t& expect);
};

void TEST_LC3202::SetUp()
{
    m_testList.push_back(new LC3202_FindTheMaximumLengthOfValidSubsequenceII_DP());
    m_testList.push_back(new LC3202_FindTheMaximumLengthOfValidSubsequenceII_Enum());
}

void TEST_LC3202::TearDown()
{
    for (LC3202_FindTheMaximumLengthOfValidSubsequenceII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3202::RunTest(std::vector<int32_t>& nums, int32_t k, int32_t& expect)
{
    for (LC3202_FindTheMaximumLengthOfValidSubsequenceII* inst : m_testList) {
        int32_t result = inst->maximumLength(nums, k);
        EXPECT_EQ(expect, result) << "nums = " << Vector2String(nums) << std::endl << "k = " << k;
    }
}

TEST_F(TEST_LC3202, case1)
{
    std::vector<int32_t> nums = CreateIntVector("[1,2,3,4,5]");
    int32_t k = 2;
    int32_t expect = 5;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC3202, case2)
{
    std::vector<int32_t> nums = CreateIntVector("[1,4,2,3,1,4]");
    int32_t k = 3;
    int32_t expect = 4;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC3202, case3)
{
    std::vector<int32_t> nums = CreateIntVector("[2,10]");
    int32_t k = 7;
    int32_t expect = 2;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC3202, case4)
{
    std::vector<int32_t> nums = CreateIntVector("[1,7,9]");
    int32_t k = 10;
    int32_t expect = 2;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC3202, case5)
{
    std::vector<int32_t> nums = CreateIntVector("[8,2,8]");
    int32_t k = 5;
    int32_t expect = 3;
    RunTest(nums, k, expect);
}
