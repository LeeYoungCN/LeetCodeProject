/*
 * Time : 2025-07-10 10:54:41
 * URL  :
 * https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-ii/description/?envType=daily-question&envId=2025-07-10
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc34xx/lc344x/lc3440_reschedule_meetings_for_maximum_free_time_ii.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3440 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3440_RescheduleMeetingsForMaximumFreeTimeII*> m_testList;
    void RunTest(int32_t eventTime, std::vector<int32_t>& startTime, std::vector<int32_t>& endTime,
                 const int32_t& expect);
};

void TEST_LC3440::SetUp()
{
    m_testList.push_back(new LC3440_RescheduleMeetingsForMaximumFreeTimeII());
}

void TEST_LC3440::TearDown()
{
    for (LC3440_RescheduleMeetingsForMaximumFreeTimeII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3440::RunTest(int32_t eventTime, std::vector<int32_t>& startTime, std::vector<int32_t>& endTime,
                          const int32_t& expect)
{
    for (LC3440_RescheduleMeetingsForMaximumFreeTimeII* inst : m_testList) {
        int32_t result = inst->maxFreeTime(eventTime, startTime, endTime);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC3440, case1)
{
    int32_t eventTime = 5;
    std::vector<int32_t> startTime = String2VecInt("[1,3]");
    std::vector<int32_t> endTime = String2VecInt("[2,5]");
    const int32_t expect = 2;
    RunTest(eventTime, startTime, endTime, expect);
}

TEST_F(TEST_LC3440, case2)
{
    int32_t eventTime = 10;
    std::vector<int32_t> startTime = String2VecInt("[0,7,9]");
    std::vector<int32_t> endTime = String2VecInt("[1,8,10]");
    const int32_t expect = 7;
    RunTest(eventTime, startTime, endTime, expect);
}

TEST_F(TEST_LC3440, case3)
{
    int32_t eventTime = 10;
    std::vector<int32_t> startTime = String2VecInt("[0,3,7,9]");
    std::vector<int32_t> endTime = String2VecInt("[1,4,8,10]");
    const int32_t expect = 6;
    RunTest(eventTime, startTime, endTime, expect);
}

TEST_F(TEST_LC3440, case4)
{
    int32_t eventTime = 34;
    std::vector<int32_t> startTime = String2VecInt("[0,17]");
    std::vector<int32_t> endTime = String2VecInt("[14,19]");
    const int32_t expect = 18;
    RunTest(eventTime, startTime, endTime, expect);
}
