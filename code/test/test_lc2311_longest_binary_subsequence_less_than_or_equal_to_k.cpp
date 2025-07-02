/*
 * Time : 2025-06-26 18:52:09
 * URL  : https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/?envType=daily-question&envId=2025-06-26
 */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <map>

#include <set>

#include <string>

#include <vector>

#include "gtest/gtest.h"
#include "lc2311_longest_binary_subsequence_less_than_or_equal_to_k.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC2311 : public testing::Test {
protected:
    static void SetUpTestSuite() {
    }

    static void TearDownTestSuite() {
    }

    void SetUp() override;

    void TearDown() override;

    vector<LC2311_LongestBinarySubsequenceLessThanOrEqualToK *> m_testList;

    void RunTest(std::string s, int k, const int &expect);
};

void TEST_LC2311::SetUp() {
    m_testList.push_back(new LC2311_LongestBinarySubsequenceLessThanOrEqualToK());
}

void TEST_LC2311::TearDown() {
    for (LC2311_LongestBinarySubsequenceLessThanOrEqualToK *inst: m_testList) {
        delete inst;
    }
}

void TEST_LC2311::RunTest(std::string s, int k, const int &expect) {
    for (LC2311_LongestBinarySubsequenceLessThanOrEqualToK *inst: m_testList) {
        int result = inst->longestSubsequence(s, k);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC2311, case1) {
    std::string s = "1001010";
    int k = 5;
    const int expect = 5;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC2311, case2) {
    std::string s = "00101001";
    int k = 1;
    const int expect = 6;
    RunTest(s, k, expect);
}
