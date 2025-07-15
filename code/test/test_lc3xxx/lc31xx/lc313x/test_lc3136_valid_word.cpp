/*
 * Time : 2025-07-15 09:29:10
 * URL  : https://leetcode.cn/problems/valid-word/submissions/644005855/?envType=daily-question&envId=2025-07-15
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc31xx/lc313x/lc3136_valid_word.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC3136 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3136_ValidWord *> m_testList;
    void RunTest(std::string word, bool &expect);
};

void TEST_LC3136::SetUp()
{
    m_testList.push_back(new LC3136_ValidWord());
}

void TEST_LC3136::TearDown()
{
    for (LC3136_ValidWord *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3136::RunTest(std::string word, bool &expect)
{
    for (LC3136_ValidWord *inst : m_testList) {
        bool result = inst->isValid(word);
        EXPECT_EQ(expect, result) << "word=" << word;
    }
}

TEST_F(TEST_LC3136, case1)
{
    std::string word = "234Adas";
    bool expect = true;
    RunTest(word, expect);
}

TEST_F(TEST_LC3136, case2)
{
    std::string word = "b3";
    bool expect = false;
    RunTest(word, expect);
}

TEST_F(TEST_LC3136, case3)
{
    std::string word = "a3$e";
    bool expect = false;
    RunTest(word, expect);
}
