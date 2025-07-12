/*
 * Time : 2025-06-08 00:54:01
 * URL  :
 * https://leetcode.cn/problems/lexicographical-numbers/description/?envType=daily-questionURL_STRenvId=2025-06-08
 */
#include <cstddef>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc03xx/lc038x/lc0386_lexicographical_numbers.h"

using namespace std;

class TEST_LC0386 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0386_LexicographicalNumbers *> m_testList;
    void RunTest(int n, vector<int> expect);
};

void TEST_LC0386::SetUp()
{
    m_testList.push_back(new LC0386_LexicographicalNumbers_Str2Num());
    m_testList.push_back(new LC0386_LexicographicalNumbers_DFS());
    m_testList.push_back(new LC0386_LexicographicalNumbers_Iterator());
}

void TEST_LC0386::TearDown()
{
    for (LC0386_LexicographicalNumbers *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0386::RunTest(int n, vector<int> expect)
{
    for (LC0386_LexicographicalNumbers *inst : m_testList) {
        vector<int> result = inst->lexicalOrder(n);
        ASSERT_EQ(expect.size(), result.size()) << "Assert size equal!";
        for (size_t i = 0; i < expect.size(); i++) {
            EXPECT_EQ(expect.at(i), result.at(i));
        }
    }
}

TEST_F(TEST_LC0386, case1)
{
    int n = 13;
    vector<int> expect = {1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9};
    RunTest(n, expect);
}

TEST_F(TEST_LC0386, case2)
{
    int n = 2;
    vector<int> expect = {1, 2};
    RunTest(n, expect);
}

TEST_F(TEST_LC0386, case3)
{
    int n = 121;
    vector<int> expect = {1,   10,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 11, 110, 111, 112, 113, 114,
                          115, 116, 117, 118, 119, 12,  120, 121, 13,  14,  15,  16,  17, 18,  19,  2,   20,  21,
                          22,  23,  24,  25,  26,  27,  28,  29,  3,   30,  31,  32,  33, 34,  35,  36,  37,  38,
                          39,  4,   40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  5,  50,  51,  52,  53,  54,
                          55,  56,  57,  58,  59,  6,   60,  61,  62,  63,  64,  65,  66, 67,  68,  69,  7,   70,
                          71,  72,  73,  74,  75,  76,  77,  78,  79,  8,   80,  81,  82, 83,  84,  85,  86,  87,
                          88,  89,  9,   90,  91,  92,  93,  94,  95,  96,  97,  98,  99};
    RunTest(n, expect);
}

TEST_F(TEST_LC0386, case4)
{
    int n = 192;
    vector<int> expect = {
        1,   10, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 11, 110, 111, 112, 113, 114, 115, 116, 117, 118,
        119, 12, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 13, 130, 131, 132, 133, 134, 135, 136, 137, 138,
        139, 14, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 15, 150, 151, 152, 153, 154, 155, 156, 157, 158,
        159, 16, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 17, 170, 171, 172, 173, 174, 175, 176, 177, 178,
        179, 18, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 19, 190, 191, 192, 2,   20,  21,  22,  23,  24,
        25,  26, 27,  28,  29,  3,   30,  31,  32,  33,  34,  35,  36, 37,  38,  39,  4,   40,  41,  42,  43,  44,
        45,  46, 47,  48,  49,  5,   50,  51,  52,  53,  54,  55,  56, 57,  58,  59,  6,   60,  61,  62,  63,  64,
        65,  66, 67,  68,  69,  7,   70,  71,  72,  73,  74,  75,  76, 77,  78,  79,  8,   80,  81,  82,  83,  84,
        85,  86, 87,  88,  89,  9,   90,  91,  92,  93,  94,  95,  96, 97,  98,  99};
    RunTest(n, expect);
}
