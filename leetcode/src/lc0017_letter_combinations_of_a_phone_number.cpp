/*
 * Time : 2025-05-19 21:27:40
 * URL  : https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 */
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include "lc0017_letter_combinations_of_a_phone_number.h"

using namespace std;

vector<string> NUM_TO_STR = {
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void Lc0017_LetterCombinationsOfAPhoneNumber::getResultByItr(uint32_t layer, string &curr, vector<string> &result)
{
    if (layer >= m_digits.size()) {
        if (!curr.empty()) {
            result.push_back(curr);
        }
        return;
    }
    char digitChar = m_digits[layer];
    string layerStr = NUM_TO_STR[digitChar - '2'];
    for (char c : layerStr) {
        curr.push_back(c);
        getResultByItr(layer + 1, curr, result);
        curr.pop_back();
    }
}

vector<string> Lc0017_LetterCombinationsOfAPhoneNumber::letterCombinations(string digits)
{
    m_digits = digits;
    vector<string> result;
    string curr;

    curr.reserve(digits.size());
    getResultByItr(0, curr, result);
    return result;
}
