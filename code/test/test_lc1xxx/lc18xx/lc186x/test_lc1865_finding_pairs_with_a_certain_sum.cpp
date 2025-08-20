/*
 * Time : 2025-07-06 08:38:55
 * URL  :
 * https://leetcode.cn/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06
 */
#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc18xx/lc186x/lc1865_finding_pairs_with_a_certain_sum.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC1865 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1865_FindingPairsWithACertainSum*> m_testList;
    void RunTest(vector<vector<int32_t>>& nums, const vector<string>& operation, const vector<vector<int32_t>>& params,
                 const vector<string>& expect);
};

void TEST_LC1865::SetUp()
{
    m_testList.push_back(new LC1865_FindingPairsWithACertainSum());
}

void TEST_LC1865::TearDown()
{
    for (LC1865_FindingPairsWithACertainSum* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1865::RunTest(vector<vector<int32_t>>& nums, const vector<string>& operation,
                          const vector<vector<int32_t>>& params, const vector<string>& expect)
{
    for (LC1865_FindingPairsWithACertainSum* inst : m_testList) {
        inst->FindSumPairs(nums[0], nums[1]);
        for (uint32_t i = 0; i < operation.size(); ++i) {
            if (operation[i] == string("count")) {
                EXPECT_EQ(inst->count(params[i][0]), stoi(expect[i])) << "count(" << params[i][0] << ")";
            } else if (operation[i] == string("add")) {
                ASSERT_EQ(params[i].size(), 2);
                inst->add(params[i][0], params[i][1]);
            } else {
                ASSERT_TRUE(false);
            }
        }
    }
}

TEST_F(TEST_LC1865, case1)
{
    vector<vector<int32_t>> nums = CreateIntMatrix("[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]]");
    vector<string> operation = {"count", "add", "count", "count", "add", "add", "count"};
    vector<vector<int32_t>> params = CreateIntMatrix("[[7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]");
    vector<string> expect = CreateStringVector("[8, null, 2, 1, null, null, 11]");

    RunTest(nums, operation, params, expect);
}
