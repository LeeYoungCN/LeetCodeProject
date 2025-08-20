/*
 * Time : 2025-07-11 10:44:22
 * URL  : https://leetcode.cn/problems/merge-intervals/
 */
#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc005x/lc0056_merge_intervals.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0056 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0056_MergeIntervals*> m_testList;
    void RunTest(std::vector<std::vector<int32_t>>& intervals, std::vector<std::vector<int32_t>>& expect);
};

void TEST_LC0056::SetUp()
{
    m_testList.push_back(new LC0056_MergeIntervals());
}

void TEST_LC0056::TearDown()
{
    for (LC0056_MergeIntervals* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0056::RunTest(std::vector<std::vector<int32_t>>& intervals, std::vector<std::vector<int32_t>>& expect)
{
    for (LC0056_MergeIntervals* inst : m_testList) {
        std::vector<std::vector<int32_t>> result = inst->merge(intervals);
        ASSERT_EQ(result.size(), expect.size());
        sort(expect.begin(), expect.end());
        sort(result.begin(), result.end());
        for (size_t i = 0; i < expect.size(); ++i) {
            ASSERT_EQ(expect[i].size(), expect[i].size());
            sort(expect[i].begin(), expect[i].end());
            sort(result[i].begin(), result[i].end());
            for (size_t j = 0; j < expect[i].size(); ++j) {
                EXPECT_EQ(expect[i][j], result[i][j]);
            }
        }
    }
}

TEST_F(TEST_LC0056, case1)
{
    std::vector<std::vector<int32_t>> intervals = CreateIntMatrix("[[1,3],[2,6],[8,10],[15,18]]");
    std::vector<std::vector<int32_t>> expect = CreateIntMatrix("[[1,6],[8,10],[15,18]]");
    RunTest(intervals, expect);
}

TEST_F(TEST_LC0056, case2)
{
    std::vector<std::vector<int32_t>> intervals = CreateIntMatrix("[[1,4],[4,5]]");
    std::vector<std::vector<int32_t>> expect = CreateIntMatrix("[[1,5]]");
    RunTest(intervals, expect);
}
