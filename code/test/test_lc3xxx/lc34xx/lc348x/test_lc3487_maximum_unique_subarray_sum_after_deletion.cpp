/*
 * Time : 2025-07-25 09:10:06
 * URL  :
 * https://leetcode.cn/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc34xx/lc348x/lc3487_maximum_unique_subarray_sum_after_deletion.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3487_Params {
public:
    TEST_LC3487_Params() = default;
    ~TEST_LC3487_Params() = default;
    TEST_LC3487_Params(const std::string &nums, int32_t expect) : nums(CreateIntVector(nums)), expect(expect) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC3487_Params &params)
    {
        os << Vector2String(params.nums);
        return os;
    };

public:
    std::vector<int32_t> nums;
    int32_t expect{};
};

class TEST_LC3487 : public ::testing::TestWithParam<TEST_LC3487_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3487_MaximumUniqueSubarraySumAfterDeletion *> m_testList;
};

void TEST_LC3487::SetUp()
{
    m_testList.push_back(new LC3487_MaximumUniqueSubarraySumAfterDeletion());
}

void TEST_LC3487::TearDown()
{
    for (LC3487_MaximumUniqueSubarraySumAfterDeletion *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC3487, case)
{
    TEST_LC3487_Params params = GetParam();
    int32_t expect = params.expect;
    for (LC3487_MaximumUniqueSubarraySumAfterDeletion *inst : m_testList) {
        int32_t result = inst->maxSum(params.nums);
        EXPECT_EQ(expect, result);
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC3487,
                         ::testing::Values(TEST_LC3487_Params("[1,2,3,4,5]", 15), TEST_LC3487_Params("1,1,0,1,1]", 1),
                                           TEST_LC3487_Params("[1,2,-1,-2,1,0,-1]", 3),
                                           TEST_LC3487_Params("[-1, -1, 0]", 0), TEST_LC3487_Params("[-1, -1]", -1)));
