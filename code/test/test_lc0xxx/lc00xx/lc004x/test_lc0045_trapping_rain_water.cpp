/*
 * Time : 2025-07-14 15:30:14
 * URL  : https://leetcode.cn/problems/trapping-rain-water/description/
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc004x/lc0045_trapping_rain_water.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0045 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0045_TrappingRainWater*> m_testList;
    void RunTest(std::vector<int32_t>& height, int32_t& expect);
};

void TEST_LC0045::SetUp()
{
    m_testList.push_back(new LC0045_TrappingRainWater_MonotonicStack());
    m_testList.push_back(new LC0045_TrappingRainWater_LeftAndRightMax());
}

void TEST_LC0045::TearDown()
{
    for (LC0045_TrappingRainWater* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0045::RunTest(std::vector<int32_t>& height, int32_t& expect)
{
    for (LC0045_TrappingRainWater* inst : m_testList) {
        int32_t result = inst->trap(height);
        EXPECT_EQ(expect, result) << Vector2String(height);
    }
}

TEST_F(TEST_LC0045, case1)
{
    std::vector<int32_t> height = String2VecInt("[2,1,3]");
    int32_t expect = 1;
    RunTest(height, expect);
}

TEST_F(TEST_LC0045, case2)
{
    std::vector<int32_t> height = String2VecInt("[1,0,0,3]");
    int32_t expect = 2;
    RunTest(height, expect);
}

TEST_F(TEST_LC0045, case3)
{
    std::vector<int32_t> height = String2VecInt("[1,0,0]");
    int32_t expect = 0;
    RunTest(height, expect);
}

TEST_F(TEST_LC0045, case4)
{
    std::vector<int32_t> height = String2VecInt("[1,2,3]");
    int32_t expect = 0;
    RunTest(height, expect);
}

TEST_F(TEST_LC0045, case5)
{
    std::vector<int32_t> height = String2VecInt("[4,2,0,3,2,5]");
    int32_t expect = 9;
    RunTest(height, expect);
}

TEST_F(TEST_LC0045, case6)
{
    std::vector<int32_t> height = String2VecInt("[0,1,0,2,1,0,1,3,2,1,2,1]");
    int32_t expect = 6;
    RunTest(height, expect);
}

TEST_F(TEST_LC0045, case7)
{
    std::vector<int32_t> height = String2VecInt("[4,2,3]");
    int32_t expect = 1;
    RunTest(height, expect);
}
