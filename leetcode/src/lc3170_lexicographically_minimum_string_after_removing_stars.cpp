/*
 * Time : 2025-06-07 00:42:01
 * URL  :
 * https://leetcode.cn/problems/lexicographically-minimum-string-after-removing-stars/description/?envType=daily-questionURL_STRenvId=2025-06-07
 */
#include "lc3170_lexicographically_minimum_string_after_removing_stars.h"

#include <algorithm>
#include <cstdint>
#include <map>
#include <queue>
#include <string>

using namespace std;

string LC3170_LexicographicallyMinimumStringAfterRemovingStars_Heap::clearStars(string s)
{
    const uint32_t length = (uint32_t)s.size();

    map<char, priority_queue<uint32_t>> charMap;
    for (uint32_t i = 0; i < length; ++i) {
        char c = s[i];
        if (c != '*') {
            charMap[c].push(i);
            continue;
        }

        s[charMap.begin()->second.top()] = '*';
        charMap.begin()->second.pop();

        if (charMap.begin()->second.empty()) {
            charMap.erase(charMap.begin());
        }
    }

    string ans;
    for (char c : s) {
        if (c != '*') {
            ans += c;
        }
    }

    return ans;
}

string LC3170_LexicographicallyMinimumStringAfterRemovingStars_Stack::clearStars(string s)
{
    const auto length = static_cast<uint32_t>(s.size());

    map<char, vector<uint32_t>> charMap;
    for (uint32_t i = 0; i < length; ++i) {
        char c = s[i];
        if (c != '*') {
            charMap[c].push_back(i);
            continue;
        }

        s[charMap.begin()->second.back()] = '*';
        charMap.begin()->second.pop_back();

        if (charMap.begin()->second.empty()) {
            charMap.erase(charMap.begin());
        }
    }

    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
}
