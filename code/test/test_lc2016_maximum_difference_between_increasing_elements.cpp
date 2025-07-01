/*
 * Time : 2025-06-16 09:06:17
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-increasing-elements/description/?envType=daily-questionURL_STRenvId=2025-06-16
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc2016_maximum_difference_between_increasing_elements.h"
#include "leetcode_utils.hpp"

using namespace std;

class TEST_LC2016 : public testing::Test {
protected:
    static void SetUpTestSuite() {}

    static void TearDownTestSuite() {}

    void SetUp() override;

    void TearDown() override;

    vector<LC2016_MaximumDifferenceBetweenIncreasingElements *> m_testList;

    void RunTest(vector<int32_t> &nums, int32_t expect) const;
};

void TEST_LC2016::SetUp()
{
    m_testList.push_back(new LC2016_MaximumDifferenceBetweenIncreasingElements_MinArray());
    m_testList.push_back(new LC2016_MaximumDifferenceBetweenIncreasingElements_PreMin());
}

void TEST_LC2016::TearDown()
{
    for (LC2016_MaximumDifferenceBetweenIncreasingElements *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2016::RunTest(vector<int32_t> &nums, const int32_t expect) const
{
    for (LC2016_MaximumDifferenceBetweenIncreasingElements *inst : m_testList) {
        const int32_t result = inst->maximumDifference(nums);
        EXPECT_EQ(expect, result) << "nums = " << Vector2String(nums) << ", expect = " << expect;
    }
}

TEST_F(TEST_LC2016, case1)
{
    vector<int32_t> nums{7, 1, 5, 4};
    constexpr int32_t expect = 4;
    RunTest(nums, expect);
}

TEST_F(TEST_LC2016, case2)
{
    vector<int32_t> nums{9, 4, 3, 2};
    constexpr int32_t expect = -1;
    RunTest(nums, expect);
}

TEST_F(TEST_LC2016, case3)
{
    vector<int32_t> nums{1, 5, 2, 10};
    constexpr int32_t expect = 9;
    RunTest(nums, expect);
}

TEST_F(TEST_LC2016, case4)
{
    vector<int32_t> nums = {999, 997, 980, 976, 948, 940, 938, 928, 924, 917, 907, 907, 881, 878, 864, 862, 859,
                            857, 848, 840, 824, 824, 824, 805, 802, 798, 788, 777, 775, 766, 755, 748, 735, 732,
                            727, 705, 700, 697, 693, 679, 676, 644, 634, 624, 599, 596, 588, 583, 562, 558, 553,
                            539, 537, 536, 509, 491, 485, 483, 454, 449, 438, 425, 403, 368, 345, 327, 287, 285,
                            270, 263, 255, 248, 235, 234, 224, 221, 201, 189, 187, 183, 179, 168, 155, 153, 150,
                            144, 107, 102, 102, 87,  80,  57,  55,  49,  48,  45,  26,  26,  23,  15};
    constexpr int32_t expect = -1;
    RunTest(nums, expect);
}
