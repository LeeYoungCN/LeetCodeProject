/*
 * Time : 2025-06-06 15:36:48
 * URL  : https://leetcode.cn/problems/find-original-array-from-doubled-array/description/
 */
#include <algorithm>
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc2007_find_original_array_from_doubled_array.h"

using namespace std;

class TEST_LC2007 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2007_FindOriginalArrayFromDoubledArray *> m_testList;
    void RunTest(vector<int> &changed, vector<int> expect);
};

void TEST_LC2007::SetUp()
{
    m_testList.push_back(new LC2007_FindOriginalArrayFromDoubledArray_Map());
}

void TEST_LC2007::TearDown()
{
    for (LC2007_FindOriginalArrayFromDoubledArray *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2007::RunTest(vector<int> &changed, vector<int> expect)
{
    for (LC2007_FindOriginalArrayFromDoubledArray *inst : m_testList) {
        vector<int> result = inst->findOriginalArray(changed);
        ASSERT_EQ(expect.size(), result.size());
        if (expect.size() == 0) {
            continue;
            ;
        }
        sort(expect.begin(), expect.end());
        sort(result.begin(), result.end());
        for (uint32_t i = 0; i < (uint32_t)expect.size(); i++) {
            EXPECT_EQ(expect.at(i), result.at(i));
        }
    }
}

TEST_F(TEST_LC2007, case1)
{
    vector<int> changed = {1, 3, 4, 2, 6, 8};
    vector<int> expect = {1, 3, 4};
    RunTest(changed, expect);
}

TEST_F(TEST_LC2007, case2)
{
    vector<int> changed = {6, 3, 0, 1};
    vector<int> expect = {};
    RunTest(changed, expect);
}

TEST_F(TEST_LC2007, case3)
{
    vector<int> changed = {1};
    vector<int> expect = {};
    RunTest(changed, expect);
}

TEST_F(TEST_LC2007, case4)
{
    vector<int> changed = {1, 2, 4, 8};
    vector<int> expect = {1, 4};
    RunTest(changed, expect);
}

TEST_F(TEST_LC2007, case5)
{
    vector<int> changed = {0, 0, 1, 2, 4, 8};
    vector<int> expect = {0, 1, 4};
    RunTest(changed, expect);
}

TEST_F(TEST_LC2007, case6)
{
    vector<int> changed = {2, 1, 2, 4, 2, 4};
    vector<int> expect = {1, 2, 2};
    RunTest(changed, expect);
}
