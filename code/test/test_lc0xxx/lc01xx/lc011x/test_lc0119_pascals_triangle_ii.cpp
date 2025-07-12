/*
 * Time : 2025-06-24 11:31:51
 * URL  : https://leetcode.cn/problems/pascals-triangle-ii/?envType=problem-list-v2&envId=dynamic-programming
 */

#include <cstddef>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc01xx/lc011x/lc0119_pascals_triangle_ii.h"

using namespace std;

class TEST_LC0119 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0119_PascalsTriangleII *> m_testList;
    void RunTest(int rowIndex, const std::vector<int> &expect);
};

void TEST_LC0119::SetUp()
{
    m_testList.push_back(new LC0119_PascalsTriangleII());
}

void TEST_LC0119::TearDown()
{
    for (LC0119_PascalsTriangleII *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0119::RunTest(int rowIndex, const std::vector<int> &expect)
{
    for (LC0119_PascalsTriangleII *inst : m_testList) {
        std::vector<int> result = inst->getRow(rowIndex);
        ASSERT_EQ(expect.size(), result.size());
        for (size_t i = 0; i < expect.size(); ++i) {
            EXPECT_EQ(expect[i], result[i]);
        }
    }
}

TEST_F(TEST_LC0119, case1)
{
    int rowIndex = 3;
    const std::vector<int> expect = {1, 3, 3, 1};
    RunTest(rowIndex, expect);
}

TEST_F(TEST_LC0119, case2)
{
    int rowIndex = 0;
    const std::vector<int> expect = {1};
    RunTest(rowIndex, expect);
}

TEST_F(TEST_LC0119, case3)
{
    int rowIndex = 1;
    const std::vector<int> expect = {1, 1};
    RunTest(rowIndex, expect);
}
