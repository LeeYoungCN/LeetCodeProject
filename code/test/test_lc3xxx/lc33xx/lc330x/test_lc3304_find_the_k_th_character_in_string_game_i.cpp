/*
 * Time : 2025-07-03 14:46:38
 * URL  :
 * https://leetcode.cn/problems/find-the-k-th-character-in-string-game-i/description/?envType=daily-question&envId=2025-07-03
 */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc33xx/lc330x/lc3304_find_the_k_th_character_in_string_game_i.h"

using namespace std;

class TEST_LC3304 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3304_FindTheKThCharacterInStringGameI *> m_testList;
    void RunTest(int32_t k, const char &expect);
};

void TEST_LC3304::SetUp()
{
    m_testList.push_back(new LC3304_FindTheKThCharacterInStringGameI());
}

void TEST_LC3304::TearDown()
{
    for (LC3304_FindTheKThCharacterInStringGameI *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3304::RunTest(int32_t k, const char &expect)
{
    for (LC3304_FindTheKThCharacterInStringGameI *inst : m_testList) {
        char result = inst->kthCharacter(k);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC3304, case1)
{
    int32_t k = 5;
    const char expect = 'b';
    RunTest(k, expect);
}

TEST_F(TEST_LC3304, case2)
{
    int32_t k = 10;
    const char expect = 'c';
    RunTest(k, expect);
}
