/*
 * Time : 2025-07-11 00:37:53
 * URL  : https://leetcode.cn/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-07-11
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc31xx/lc316x/lc3169_count_days_without_meetings.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3169 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3169_CountDaysWithoutMeetings*> m_testList;
    void RunTest(int32_t days, std::vector<std::vector<int32_t>>& meetings, const int32_t& expect);
};

void TEST_LC3169::SetUp()
{
    m_testList.push_back(new LC3169_CountDaysWithoutMeetings());
}

void TEST_LC3169::TearDown()
{
    for (LC3169_CountDaysWithoutMeetings* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3169::RunTest(int32_t days, std::vector<std::vector<int32_t>>& meetings, const int32_t& expect)
{
    for (LC3169_CountDaysWithoutMeetings* inst : m_testList) {
        int32_t result = inst->countDays(days, meetings);
        EXPECT_EQ(expect, result) << Matrix2String(meetings);
    }
}

TEST_F(TEST_LC3169, case1)
{
    int32_t days = 10;
    std::vector<std::vector<int32_t>> meetings = CreateIntMatrix("[[5,7],[1,3],[9,10]]");
    const int32_t expect = 2;
    RunTest(days, meetings, expect);
}

TEST_F(TEST_LC3169, case2)
{
    int32_t days = 5;
    std::vector<std::vector<int32_t>> meetings = CreateIntMatrix("[[2,4],[1,3]]");
    const int32_t expect = 1;
    RunTest(days, meetings, expect);
}

TEST_F(TEST_LC3169, case3)
{
    int32_t days = 6;
    std::vector<std::vector<int32_t>> meetings = CreateIntMatrix("[[1,6]]");
    const int32_t expect = 0;
    RunTest(days, meetings, expect);
}

TEST_F(TEST_LC3169, case4)
{
    int32_t days = 57;
    std::vector<std::vector<int32_t>> meetings =
        CreateIntMatrix("[[3,49],[23,44],[21,56],[26,55],[23,52],[2,9],[1,48],[3,31]]");
    const int32_t expect = 1;
    RunTest(days, meetings, expect);
}

TEST_F(TEST_LC3169, case5)
{
    int32_t days = 7;
    std::vector<std::vector<int32_t>> meetings = CreateIntMatrix("[[1,6],[2,3],[3,4]]");
    const int32_t expect = 1;
    RunTest(days, meetings, expect);
}
