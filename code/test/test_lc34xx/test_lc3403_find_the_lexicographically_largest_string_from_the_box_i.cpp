/*
 * Time : 2025-06-04 07:33:18
 * URL  :
 * https://leetcode.cn/problems/find-the-lexicographically-largest-string-from-the-box-i/description/?envType=daily-questionURL_STRenvId=2025-06-04
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc34xx/lc3403_find_the_lexicographically_largest_string_from_the_box_i.h"

using namespace std;

class TEST_LC3403 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3403_FindTheLexicographicallyLargestStringFromTheBoxI *> m_testList;
    void RunTest(std::string word, int numFriends, std::string expect);
};

void TEST_LC3403::SetUp()
{
    m_testList.push_back(new LC3403_FindTheLexicographicallyLargestStringFromTheBoxI());
}

void TEST_LC3403::TearDown()
{
    for (LC3403_FindTheLexicographicallyLargestStringFromTheBoxI *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3403::RunTest(std::string word, int numFriends, std::string expect)
{
    for (LC3403_FindTheLexicographicallyLargestStringFromTheBoxI *inst : m_testList) {
        EXPECT_EQ(expect, inst->answerString(word, numFriends));
    }
}

TEST_F(TEST_LC3403, case1)
{
    std::string word = "dbca";
    int numFriends = 2;
    std::string expect = "dbc";
    RunTest(word, numFriends, expect);
}

TEST_F(TEST_LC3403, case2)
{
    std::string word = "gggg";
    int numFriends = 4;
    std::string expect = "g";
    RunTest(word, numFriends, expect);
}
