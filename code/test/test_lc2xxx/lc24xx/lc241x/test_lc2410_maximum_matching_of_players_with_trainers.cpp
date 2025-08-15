/*
 * Time : 2025-07-13 12:37:24
 * URL  :
 * https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/description/?envType=daily-question&envId=2025-07-13
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc2xxx/lc24xx/lc241x/lc2410_maximum_matching_of_players_with_trainers.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC2410 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2410_MaximumMatchingOfPlayersWithTrainers*> m_testList;
    void RunTest(std::vector<int32_t>& players, std::vector<int32_t>& trainers, int32_t& expect);
};

void TEST_LC2410::SetUp()
{
    m_testList.push_back(new LC2410_MaximumMatchingOfPlayersWithTrainers());
}

void TEST_LC2410::TearDown()
{
    for (LC2410_MaximumMatchingOfPlayersWithTrainers* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2410::RunTest(std::vector<int32_t>& players, std::vector<int32_t>& trainers, int32_t& expect)
{
    for (LC2410_MaximumMatchingOfPlayersWithTrainers* inst : m_testList) {
        int32_t result = inst->matchPlayersAndTrainers(players, trainers);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC2410, case1)
{
    std::vector<int32_t> players = CreateIntVector("[4,7,9]");
    std::vector<int32_t> trainers = CreateIntVector("[8,2,5,8]");
    int32_t expect = 2;
    RunTest(players, trainers, expect);
}

TEST_F(TEST_LC2410, case2)
{
    std::vector<int32_t> players = CreateIntVector("[1,1,1]");
    std::vector<int32_t> trainers = CreateIntVector("[10]");
    int32_t expect = 1;
    RunTest(players, trainers, expect);
}

TEST_F(TEST_LC2410, case3)
{
    std::vector<int32_t> players = CreateIntVector("[1]");
    std::vector<int32_t> trainers = CreateIntVector("[1]");
    int32_t expect = 1;
    RunTest(players, trainers, expect);
}
