/*
 * Time : 2025-05-24 00:13:40
 * URL  :
 * https://leetcode.cn/problems/find-words-containing-character/description/?envType=daily-questionURL_STRenvId=2025-05-24
 */
#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc2xxx/lc29xx/lc294x/lc2942_find_words_containing_character.h"

using namespace std;

class TEST_LC2942 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2942_FindWordsContainingCharacter*> m_testList;
    void RunTest(vector<string>& words, char x, const vector<int32_t>& expect);
};

void TEST_LC2942::SetUp()
{
    m_testList.push_back(new LC2942_FindWordsContainingCharacter());
}

void TEST_LC2942::TearDown()
{
    for (LC2942_FindWordsContainingCharacter* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2942::RunTest(vector<string>& words, char x, const vector<int32_t>& expect)
{
    for (LC2942_FindWordsContainingCharacter* inst : m_testList) {
        vector<int32_t> result = inst->findWordsContaining(words, x);
        EXPECT_EQ(expect.size(), expect.size());
        for (uint32_t i = 0; i < result.size(); i++) {
            EXPECT_EQ(expect.at(i), result.at(i))
                << "i = " << i << ", expect = " << expect.at(i) << ", result = " << result.at(i);
        }
    }
}

TEST_F(TEST_LC2942, case1)
{
    vector<string> words = {"leet", "code"};
    char x = 'e';
    vector<int> expect = {0, 1};
    RunTest(words, x, expect);
}

TEST_F(TEST_LC2942, case2)
{
    vector<string> words = {"abc", "bcd", "aaaa", "cbc"};
    char x = 'a';
    vector<int> expect = {0, 2};
    RunTest(words, x, expect);
}

TEST_F(TEST_LC2942, case3)
{
    vector<string> words = {"abc", "bcd", "aaaa", "cbc"};
    char x = 'z';
    vector<int> expect = {};
    RunTest(words, x, expect);
}
