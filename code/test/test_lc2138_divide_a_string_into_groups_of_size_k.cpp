/*
 * Time : 2025-06-22 14:42:38
 * URL  :
 * https://leetcode.cn/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22
 */

#include <cstddef>
#include <cstdio>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc2138_divide_a_string_into_groups_of_size_k.h"

using namespace std;

class TEST_LC2138 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2138_DivideAStringIntoGroupsOfSizeK *> m_testList;
    void RunTest(std::string s, int k, char fill, const std::vector<std::string> &expect);
};

void TEST_LC2138::SetUp()
{
    m_testList.push_back(new LC2138_DivideAStringIntoGroupsOfSizeK());
}

void TEST_LC2138::TearDown()
{
    for (LC2138_DivideAStringIntoGroupsOfSizeK *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2138::RunTest(std::string s, int k, char fill, const std::vector<std::string> &expect)
{
    for (LC2138_DivideAStringIntoGroupsOfSizeK *inst : m_testList) {
        std::vector<std::string> result = inst->divideString(s, k, fill);
        ASSERT_EQ(expect.size(), result.size());
        for (size_t i = 0; i < expect.size(); i++) {
            EXPECT_EQ(expect[i], result[i]);
        }
    }
}

TEST_F(TEST_LC2138, case1)
{
    std::string s = "abcdefghi";
    int k = 3;
    char fill = 'x';
    const std::vector<std::string> expect = {"abc", "def", "ghi"};
    RunTest(s, k, fill, expect);
}

TEST_F(TEST_LC2138, case2)
{
    std::string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    const std::vector<std::string> expect = {"abc", "def", "ghi", "jxx"};
    RunTest(s, k, fill, expect);
}
