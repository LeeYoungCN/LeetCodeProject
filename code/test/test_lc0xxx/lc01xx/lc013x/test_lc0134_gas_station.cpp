/*
 * Time : 2025-07-06 15:25:28
 * URL  : https://leetcode.cn/problems/gas-station/description/?envType=problem-list-v2&envId=greedy
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc01xx/lc013x/lc0134_gas_station.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0134 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0134_GasStation*> m_testList;
    void RunTest(std::vector<int32_t>& gas, std::vector<int32_t>& cost, const int32_t& expect);
};

void TEST_LC0134::SetUp()
{
    m_testList.push_back(new LC0134_GasStation());
}

void TEST_LC0134::TearDown()
{
    for (LC0134_GasStation* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0134::RunTest(std::vector<int32_t>& gas, std::vector<int32_t>& cost, const int32_t& expect)
{
    for (LC0134_GasStation* inst : m_testList) {
        int32_t result = inst->canCompleteCircuit(gas, cost);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0134, case1)
{
    std::vector<int32_t> gas = String2VecInt("[1,2,3,4,5]");
    std::vector<int32_t> cost = String2VecInt("[3,4,5,1,2]");
    const int32_t expect = 3;
    RunTest(gas, cost, expect);
}

TEST_F(TEST_LC0134, case2)
{
    std::vector<int32_t> gas = String2VecInt("[2,3,4]");
    std::vector<int32_t> cost = String2VecInt("[3,4,3]");
    const int32_t expect = -1;
    RunTest(gas, cost, expect);
}

TEST_F(TEST_LC0134, case3)
{
    std::vector<int32_t> gas = String2VecInt("[5,1,2,3,4]");
    std::vector<int32_t> cost = String2VecInt("[4,4,1,5,1]");
    const int32_t expect = 4;
    RunTest(gas, cost, expect);
}

TEST_F(TEST_LC0134, case4)
{
    std::vector<int32_t> gas = String2VecInt("[2]");
    std::vector<int32_t> cost = String2VecInt("[2]");
    const int32_t expect = 0;
    RunTest(gas, cost, expect);
}
