/*
 * Time : 2025-06-06 01:21:03
 * URL  :
 * https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/?envType=daily-questionURL_STRenvId=2025-06-06
 */

#include "lc2434_using_a_robot_to_print_the_lexicographically_smallest_string.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

string LC2434_UsingARobotToPrintTheLexicographicallySmallestString::robotWithString(string s)
{
    const uint32_t length = (uint32_t)s.size();
    if (length == 1) {
        return s;
    }

    vector<char> dp(length + 1, 0);
    dp[length] = 'z';

    for (uint32_t i = 0; i < length; i++) {
        uint32_t j = length - i - 1;
        dp[j] = min(s[j], dp[j + 1]);
    }

    vector<char> stack;
    stack.reserve(length);

    string ans = "";

    for (uint32_t i = 0; i < length; i++) {
        stack.push_back(s[i]);

        while (!stack.empty() && stack.back() <= dp[i + 1]) {
            ans += stack.back();
            stack.pop_back();
        }
    }

    return ans;
}
