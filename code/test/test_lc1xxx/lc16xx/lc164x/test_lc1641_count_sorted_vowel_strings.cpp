/*
 * Time : 2025-07-18 16:36:45
 * URL  :
 * https://leetcode.cn/problems/count-sorted-vowel-strings/description/?envType=problem-list-v2&envId=dynamic-programming
 */

#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc16xx/lc164x/lc1641_count_sorted_vowel_strings.h"

using namespace std;

class TEST_LC1641_Params {
public:
    TEST_LC1641_Params() = default;
    ~TEST_LC1641_Params() = default;
    TEST_LC1641_Params(int32_t n, int32_t expect) : n(n), expect(expect) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC1641_Params &params)
    {
        os << "n: " << params.n;
        return os;
    };

public:
    int32_t n{};
    int32_t expect{};
};

class TEST_LC1641 : public ::testing::TestWithParam<TEST_LC1641_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1641_CountSortedVowelStrings *> m_testList;
};

void TEST_LC1641::SetUp()
{
    m_testList.push_back(new LC1641_CountSortedVowelStrings());
}

void TEST_LC1641::TearDown()
{
    for (LC1641_CountSortedVowelStrings *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC1641, case)
{
    TEST_LC1641_Params params = GetParam();
    int32_t expect = params.expect;
    for (LC1641_CountSortedVowelStrings *inst : m_testList) {
        int32_t result = inst->countVowelStrings(params.n);
        EXPECT_EQ(expect, result);
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC1641,
                         ::testing::Values(TEST_LC1641_Params(1, 5), TEST_LC1641_Params(2, 15),
                                           TEST_LC1641_Params(3, 35), TEST_LC1641_Params(33, 66045)));
