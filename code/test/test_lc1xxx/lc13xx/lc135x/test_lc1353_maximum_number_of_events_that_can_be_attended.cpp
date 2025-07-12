/*
 * Time : 2025-07-07 09:05:44
 * URL  :
 * https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/description/?envType=daily-question&envId=2025-07-07
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc13xx/lc135x/lc1353_maximum_number_of_events_that_can_be_attended.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC1353 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1353_MaximumNumberOfEventsThatCanBeAttended*> m_testList;
    void RunTest(std::vector<std::vector<int32_t>>& events, const int32_t& expect);
};

void TEST_LC1353::SetUp()
{
    m_testList.push_back(new LC1353_MaximumNumberOfEventsThatCanBeAttended());
}

void TEST_LC1353::TearDown()
{
    for (LC1353_MaximumNumberOfEventsThatCanBeAttended* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1353::RunTest(std::vector<std::vector<int32_t>>& events, const int32_t& expect)
{
    for (LC1353_MaximumNumberOfEventsThatCanBeAttended* inst : m_testList) {
        int32_t result = inst->maxEvents(events);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC1353, case1)
{
    std::vector<std::vector<int32_t>> events = String2MatrixInt("[[1,2],[2,3],[3,4]]");
    const int32_t expect = 3;
    RunTest(events, expect);
}

TEST_F(TEST_LC1353, case2)
{
    std::vector<std::vector<int32_t>> events = String2MatrixInt("[[1,2],[2,3],[3,4],[1,2]]");
    const int32_t expect = 4;
    RunTest(events, expect);
}

TEST_F(TEST_LC1353, case3)
{
    std::vector<std::vector<int32_t>> events = String2MatrixInt("[[1,2],[2,3],[3,4],[1,2],[1,5]]");
    const int32_t expect = 5;
    RunTest(events, expect);
}

TEST_F(TEST_LC1353, case4)
{
    std::vector<std::vector<int32_t>> events = String2MatrixInt("[[1,2],[2,3],[3,4],[1,2],[1,2]]");
    const int32_t expect = 4;
    RunTest(events, expect);
}

TEST_F(TEST_LC1353, case5)
{
    std::vector<std::vector<int32_t>> events = String2MatrixInt("[[1,2],[2,2],[3,3],[3,4],[3,4]]");
    const int32_t expect = 4;
    RunTest(events, expect);
}
