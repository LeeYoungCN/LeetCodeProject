/*
 * Time : 2025-07-21 08:51:35
 * URL  :
 * https://leetcode.cn/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2025-07-21
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc19xx/lc195x/lc1957_delete_characters_to_make_fancy_string.h"

using namespace std;

class TEST_LC1957_Params {
public:
    TEST_LC1957_Params() = default;
    ~TEST_LC1957_Params() = default;
    TEST_LC1957_Params(const std::string &&s, const std::string &&expect) : s(s), expect(expect) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC1957_Params &params)
    {
        os << params.s;
        return os;
    };

public:
    std::string s;
    std::string expect{};
};

class TEST_LC1957 : public ::testing::TestWithParam<TEST_LC1957_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1957_DeleteCharactersToMakeFancyString *> m_testList;
};

void TEST_LC1957::SetUp()
{
    m_testList.push_back(new LC1957_DeleteCharactersToMakeFancyString());
}

void TEST_LC1957::TearDown()
{
    for (LC1957_DeleteCharactersToMakeFancyString *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC1957, case)
{
    const TEST_LC1957_Params &params = GetParam();
    std::string expect = params.expect;
    for (LC1957_DeleteCharactersToMakeFancyString *inst : m_testList) {
        std::string result = inst->makeFancyString(params.s);
        EXPECT_EQ(expect, result);
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC1957,
                         ::testing::Values(TEST_LC1957_Params("leeetcode", "leetcode"),
                                           TEST_LC1957_Params("aaabaaaa", "aabaa"), TEST_LC1957_Params("aab", "aab")));
