/*
 * Time : 2025-05-25 08:55:42
 * URL  :
 * https://leetcode.cn/problems/longest-palindrome-by-concatenating-two-letter-words/?envType=daily-questionURL_STRenvId=2025-05-25
 */
#include "lc21xx/lc2131_longest_palindrome_by_concatenating_two_letter_words.h"

#include <algorithm>
#include <cstdint>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int LC2131_LongestPalindromeByConcatenatingTwoLetterWords::longestPalindrome(vector<string> &words)
{
    map<string, int32_t> wordMap;

    for (const string &word : words) {
        wordMap[word]++;
    }
    bool haveMid = false;
    int32_t ret = 0;
    for (const auto &[word, cnt] : wordMap) {
        if (cnt == 0) {
            continue;
        }

        if (word[0] == word[1]) {
            ret += (cnt / 2) * 4;
            if (cnt % 2 == 1 && !haveMid) {
                ret += 2;
                haveMid = true;
            }
            continue;
        }

        const string revWord = {word[1], word[0]};
        if (wordMap[revWord] == 0) {
            continue;
        }

        const int32_t n = min(wordMap[revWord], cnt);
        ret += (4 * n);
        wordMap[revWord] = 0;
    }
    return ret;
}
