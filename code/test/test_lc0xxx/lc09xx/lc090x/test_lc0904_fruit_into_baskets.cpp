/*
 * Time : 2025-08-05 11:20:31
 * URL  : https://leetcode.cn/problems/fruit-into-baskets/?envType=daily-question&envId=2025-08-05
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc09xx/lc090x/lc0904_fruit_into_baskets.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0904_Params {
public:
    TEST_LC0904_Params() = default;
    ~TEST_LC0904_Params() = default;
    TEST_LC0904_Params(const std::string &fruits, int32_t expect) : fruits(String2VecInt(fruits)), expect(expect) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC0904_Params &params)
    {
        os << Vector2String(params.fruits);
        return os;
    };

public:
    std::vector<int32_t> fruits;
    int32_t expect{};
};

class TEST_LC0904 : public ::testing::TestWithParam<TEST_LC0904_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0904_FruitIntoBaskets *> m_testList;
};

void TEST_LC0904::SetUp()
{
    m_testList.push_back(new LC0904_FruitIntoBaskets());
}

void TEST_LC0904::TearDown()
{
    for (LC0904_FruitIntoBaskets *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC0904, case)
{
    TEST_LC0904_Params params = GetParam();
    int32_t expect = params.expect;
    for (LC0904_FruitIntoBaskets *inst : m_testList) {
        int32_t result = inst->totalFruit(params.fruits);
        EXPECT_EQ(expect, result);
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC0904,
                         ::testing::Values(TEST_LC0904_Params("[1,2,1]", 3), TEST_LC0904_Params("[0,1,2,2]", 3),
                                           TEST_LC0904_Params("[1,2,3,2,2]", 4),
                                           TEST_LC0904_Params("[3,3,3,1,2,1,1,2,3,3,4]", 5),
                                           TEST_LC0904_Params("[0,0,1,1]", 4), TEST_LC0904_Params("[0,1,6,6,4,4,6]", 5),
                                           TEST_LC0904_Params("[1,0,1,4,1,4,1,2,3]", 5)));
