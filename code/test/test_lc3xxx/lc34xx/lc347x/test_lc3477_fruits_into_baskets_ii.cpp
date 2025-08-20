/*
 * Time : 2025-08-05 10:10:01
 * URL  : https://leetcode.cn/problems/fruits-into-baskets-ii/?envType=daily-question&envId=2025-08-05
 */

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc34xx/lc347x/lc3477_fruits_into_baskets_ii.h"
#include "leetcode_utils/leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3477_Params {
public:
    TEST_LC3477_Params() = default;
    ~TEST_LC3477_Params() = default;
    TEST_LC3477_Params(const std::string &fruits, const std::string &baskets, int32_t expect)
        : fruits(CreateIntVector(fruits)), baskets(CreateIntVector(baskets)), expect(expect) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC3477_Params &params)
    {
        os << "fruits: " << Vector2String(params.fruits) << "; " << "baskets: " << Vector2String(params.baskets);
        return os;
    };

public:
    std::vector<int32_t> fruits;
    std::vector<int32_t> baskets;
    int32_t expect{};
};

class TEST_LC3477 : public ::testing::TestWithParam<TEST_LC3477_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3477_FruitsIntoBasketsII *> m_testList;
};

void TEST_LC3477::SetUp()
{
    m_testList.push_back(new LC3477_FruitsIntoBasketsII());
}

void TEST_LC3477::TearDown()
{
    for (LC3477_FruitsIntoBasketsII *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC3477, case)
{
    TEST_LC3477_Params params = GetParam();
    int32_t expect = params.expect;
    for (LC3477_FruitsIntoBasketsII *inst : m_testList) {
        int32_t result = inst->numOfUnplacedFruits(params.fruits, params.baskets);
        EXPECT_EQ(expect, result);
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC3477,
                         ::testing::Values(TEST_LC3477_Params("[4,2,5]", "[3,5,4]", 1),
                                           TEST_LC3477_Params("[3,6,1]", "[6,4,7]", 0)));
