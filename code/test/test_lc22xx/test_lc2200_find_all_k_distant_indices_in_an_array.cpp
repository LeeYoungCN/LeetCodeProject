/*
 * Time : 2025-06-24 00:25:16
 * URL  :
 * https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/description/?envType=daily-question&envId=2025-06-24
 */

#include <cstddef>
#include <vector>

#include "gtest/gtest.h"
#include "lc22xx/lc2200_find_all_k_distant_indices_in_an_array.h"

using namespace std;

class TEST_LC2200 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2200_FindAllKDistantIndicesInAnArray*> m_testList;
    void RunTest(std::vector<int>& nums, int key, int k, const std::vector<int>& expect);
};

void TEST_LC2200::SetUp()
{
    m_testList.push_back(new LC2200_FindAllKDistantIndicesInAnArray());
}

void TEST_LC2200::TearDown()
{
    for (LC2200_FindAllKDistantIndicesInAnArray* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2200::RunTest(std::vector<int>& nums, int key, int k, const std::vector<int>& expect)
{
    for (LC2200_FindAllKDistantIndicesInAnArray* inst : m_testList) {
        std::vector<int> result = inst->findKDistantIndices(nums, key, k);
        ASSERT_EQ(expect.size(), result.size());
        for (size_t i = 0; i < expect.size(); ++i) {
            EXPECT_EQ(expect[i], result[i]);
        }
    }
}

TEST_F(TEST_LC2200, case1)
{
    std::vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;
    const std::vector<int> expect = {1, 2, 3, 4, 5, 6};
    RunTest(nums, key, k, expect);
}

TEST_F(TEST_LC2200, case2)
{
    std::vector<int> nums = {2, 2, 2, 2, 2};
    int key = 2;
    int k = 2;
    const std::vector<int> expect = {0, 1, 2, 3, 4};
    RunTest(nums, key, k, expect);
}
