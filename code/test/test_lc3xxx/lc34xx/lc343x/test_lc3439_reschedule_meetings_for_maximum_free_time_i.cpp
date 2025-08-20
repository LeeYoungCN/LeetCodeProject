/*
 * Time : 2025-07-09 10:20:38
 * URL  :
 * https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-i/description/?envType=daily-question&envId=2025-07-09
 */
#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc34xx/lc343x/lc3439_reschedule_meetings_for_maximum_free_time_i.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3439 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3439_RescheduleMeetingsForMaximumFreeTimeI*> m_testList;
    void RunTest(int32_t eventTime, int32_t k, std::vector<int32_t>& startTime, std::vector<int32_t>& endTime,
                 const int32_t& expect);
};

void TEST_LC3439::SetUp()
{
    m_testList.push_back(new LC3439_RescheduleMeetingsForMaximumFreeTimeI());
}

void TEST_LC3439::TearDown()
{
    for (LC3439_RescheduleMeetingsForMaximumFreeTimeI* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3439::RunTest(int32_t eventTime, int32_t k, std::vector<int32_t>& startTime, std::vector<int32_t>& endTime,
                          const int32_t& expect)
{
    for (LC3439_RescheduleMeetingsForMaximumFreeTimeI* inst : m_testList) {
        int32_t result = inst->maxFreeTime(eventTime, k, startTime, endTime);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC3439, case1)
{
    int32_t eventTime = 5;
    int32_t k = 1;
    std::vector<int32_t> startTime = CreateIntVector("[1,3]");
    std::vector<int32_t> endTime = CreateIntVector("[2,5]");
    const int32_t expect = 2;
    RunTest(eventTime, k, startTime, endTime, expect);
}

TEST_F(TEST_LC3439, case2)
{
    int32_t eventTime = 10;
    int32_t k = 1;
    std::vector<int32_t> startTime = CreateIntVector("[0,2,9]");
    std::vector<int32_t> endTime = CreateIntVector("[1,4,10]");
    const int32_t expect = 6;
    RunTest(eventTime, k, startTime, endTime, expect);
}

TEST_F(TEST_LC3439, case3)
{
    int32_t eventTime = 5;
    int32_t k = 2;
    std::vector<int32_t> startTime = CreateIntVector("[0,1,2,3,4]");
    std::vector<int32_t> endTime = CreateIntVector("[1,2,3,4,5]");
    const int32_t expect = 0;
    RunTest(eventTime, k, startTime, endTime, expect);
}
