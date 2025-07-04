/*
 * Time : 2025-07-03 15:31:31
 * URL  : https://leetcode.cn/problems/find-the-k-th-character-in-string-game-ii/description/
 */

#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3307_find_the_k_th_character_in_string_game_ii.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3307 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3307_FindTheKThCharacterInStringGameII*> m_testList;
    void RunTest(long long k, vector<int>& operations, const char& expect);
};

void TEST_LC3307::SetUp()
{
    m_testList.push_back(new LC3307_FindTheKThCharacterInStringGameII());
}

void TEST_LC3307::TearDown()
{
    for (LC3307_FindTheKThCharacterInStringGameII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3307::RunTest(long long k, vector<int>& operations, const char& expect)
{
    for (LC3307_FindTheKThCharacterInStringGameII* inst : m_testList) {
        char result = inst->kthCharacter(k, operations);
        EXPECT_EQ(expect, result) << Vector2String(operations);
    }
}

TEST_F(TEST_LC3307, case1)
{
    long long k = 5;
    vector<int> operations = String2VecInt("[0,0,0]");
    const char expect = 'a';
    RunTest(k, operations, expect);
}

TEST_F(TEST_LC3307, case2)
{
    long long k = 10;
    vector<int> operations = String2VecInt("[0,1,0,1]");
    const char expect = 'b';
    RunTest(k, operations, expect);
}

TEST_F(TEST_LC3307, case3)
{
    long long k = 10;
    vector<int> operations = String2VecInt("[1,0,0,1]");
    const char expect = 'c';
    RunTest(k, operations, expect);
}

TEST_F(TEST_LC3307, case4)
{
    long long k = 12145134613;
    vector<int> operations = String2VecInt("[0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1,1,1]");

    const char expect = 'i';
    RunTest(k, operations, expect);
}

TEST_F(TEST_LC3307, case5)
{
    long long k = 1;
    vector<int> operations = String2VecInt("[1,0]");
    const char expect = 'a';
    RunTest(k, operations, expect);
}

TEST_F(TEST_LC3307, case6)
{
    long long k = 4;
    vector<int> operations = String2VecInt("[1,0]");
    const char expect = 'b';
    RunTest(k, operations, expect);
}
