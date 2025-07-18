/*
 * Time : 2025-07-17 16:47:02
 * URL  : https://leetcode.cn/problems/maximum-height-of-a-triangle/
 */

#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc32xx/lc320x/lc3200_maximum_height_of_a_triangle.h"

using namespace std;

struct TEST_LC3200_Params {
    int32_t red;
    int32_t blue;
    int32_t expect;
};

class TEST_LC3200 : public ::testing::TestWithParam<TEST_LC3200_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3200_MaximumHeightOfATriangle *> m_testList;
};

void TEST_LC3200::SetUp()
{
    m_testList.push_back(new LC3200_MaximumHeightOfATriangle());
}

void TEST_LC3200::TearDown()
{
    for (LC3200_MaximumHeightOfATriangle *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC3200, case)
{
    const auto &params = GetParam();
    for (LC3200_MaximumHeightOfATriangle *inst : m_testList) {
        int32_t result = inst->maxHeightOfTriangle(params.red, params.blue);
        EXPECT_EQ(params.expect, result) << "red = " << params.red << std::endl << "blue = " << params.blue;
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC3200,
                         ::testing::Values(TEST_LC3200_Params{2, 4, 3}, TEST_LC3200_Params{2, 1, 2},
                                           TEST_LC3200_Params{1, 1, 1}));
