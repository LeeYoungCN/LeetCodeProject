/*
 * Time : 2025-08-14 08:45:21
 * URL  :
 * https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/?envType=daily-question&envId=2025-08-14
 */

#include <cstdint>
#include <format>
#include <string>
#include <utility>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc33xx/lc333x/lc3335_total_characters_in_string_after_transformations_i.h"

using namespace std;

class TEST_LC3335_Params {
public:
    TEST_LC3335_Params() = default;
    ~TEST_LC3335_Params() = default;
    TEST_LC3335_Params(std::string s, int32_t t, int32_t expect) : s(std::move(s)), t(t), expect(expect) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC3335_Params &params)
    {
        os << std::format("s: \"{}\", t: {}", params.s, params.t);
        return os;
    };

public:
    std::string s;
    int32_t t{};
    int32_t expect{};
};

class TEST_LC3335 : public ::testing::TestWithParam<TEST_LC3335_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3335_TotalCharactersInStringAfterTransformationsI *> m_testList;
};

void TEST_LC3335::SetUp()
{
    m_testList.push_back(new LC3335_TotalCharactersInStringAfterTransformationsI());
}

void TEST_LC3335::TearDown()
{
    for (LC3335_TotalCharactersInStringAfterTransformationsI *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC3335, case)
{
    const TEST_LC3335_Params &params = GetParam();
    int32_t expect = params.expect;
    for (LC3335_TotalCharactersInStringAfterTransformationsI *inst : m_testList) {
        int32_t result = inst->lengthAfterTransformations(params.s, params.t);
        EXPECT_EQ(expect, result);
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC3335,
                         ::testing::Values(TEST_LC3335_Params("abcyy", 2, 7), TEST_LC3335_Params("azbk", 1, 5),
                                           TEST_LC3335_Params("jqktcurgdvlibczdsvnsg", 7517, 79033769)));
