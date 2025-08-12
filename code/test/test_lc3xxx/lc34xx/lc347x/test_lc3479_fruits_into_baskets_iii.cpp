/*
 * Time : 2025-08-12 09:27:14
 * URL  : https://leetcode.cn/problems/fruits-into-baskets-iii/?envType=daily-question&envId=2025-08-12
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc34xx/lc347x/lc3479_fruits_into_baskets_iii.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3479_Params {
public:
    TEST_LC3479_Params() = default;
    ~TEST_LC3479_Params() = default;
    TEST_LC3479_Params(const std::string &fruits, const std::string &baskets, int32_t expect)
        : fruits(String2VecInt(fruits)), baskets(String2VecInt(baskets)), expect(expect) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC3479_Params &params)
    {
        os << "fruit: " << Vector2String(params.fruits) << ", baskets: " << Vector2String(params.baskets);
        return os;
    };

public:
    std::vector<int32_t> fruits;
    std::vector<int32_t> baskets;
    int32_t expect{};
};

class TEST_LC3479 : public ::testing::TestWithParam<TEST_LC3479_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3479_FruitsIntoBasketsIII *> m_testList;
};

void TEST_LC3479::SetUp()
{
    m_testList.push_back(new LC3479_FruitsIntoBasketsIII_Node());
}

void TEST_LC3479::TearDown()
{
    for (LC3479_FruitsIntoBasketsIII *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC3479, case)
{
    TEST_LC3479_Params params = GetParam();
    int32_t expect = params.expect;
    for (LC3479_FruitsIntoBasketsIII *inst : m_testList) {
        int32_t result = inst->numOfUnplacedFruits(params.fruits, params.baskets);
        EXPECT_EQ(expect, result);
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC3479,
                         ::testing::Values(TEST_LC3479_Params("[4,2,5]", "[3,5,4]", 1),
                                           TEST_LC3479_Params("[3,6,1]", "[6,4,7]", 0)));
