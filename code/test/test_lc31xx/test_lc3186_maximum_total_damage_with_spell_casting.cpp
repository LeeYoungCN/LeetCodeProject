/*
 * Time : 2025-06-02 23:56:29
 * URL  : https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc31xx/lc3186_maximum_total_damage_with_spell_casting.h"

using namespace std;

class TEST_LC3186 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3186_MaximumTotalDamageWithSpellCasting *> m_testList;
    void RunTest(std::vector<int> &power, long long expect);
};

void TEST_LC3186::SetUp()
{
    m_testList.push_back(new LC3186_MaximumTotalDamageWithSpellCasting());
}

void TEST_LC3186::TearDown()
{
    for (LC3186_MaximumTotalDamageWithSpellCasting *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3186::RunTest(std::vector<int> &power, long long expect)
{
    for (LC3186_MaximumTotalDamageWithSpellCasting *inst : m_testList) {
        EXPECT_EQ(expect, inst->maximumTotalDamage(power));
    }
}

TEST_F(TEST_LC3186, case1)
{
    std::vector<int> power = {1, 1, 3, 4};
    long long expect = 6;
    RunTest(power, expect);
}

TEST_F(TEST_LC3186, case2)
{
    std::vector<int> power = {7, 1, 6, 6};
    long long expect = 13;
    RunTest(power, expect);
}

TEST_F(TEST_LC3186, case3)
{
    std::vector<int> power = {7, 1, 6, 3};
    long long expect = 10;
    RunTest(power, expect);
}
