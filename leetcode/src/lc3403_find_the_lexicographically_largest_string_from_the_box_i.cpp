/*
 * Time : 2025-06-04 07:33:18
 * URL  :
 * https://leetcode.cn/problems/find-the-lexicographically-largest-string-from-the-box-i/description/?envType=daily-questionURL_STRenvId=2025-06-04
 */
#include "lc3403_find_the_lexicographically_largest_string_from_the_box_i.h"

#include <algorithm>
#include <cstdint>
#include <deque>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

namespace {

}

std::string LC3403_FindTheLexicographicallyLargestStringFromTheBoxI::answerString(std::string word, int numFriends)
{
    const auto length = static_cast<uint32_t>(word.length());
    if (numFriends == 1) {
        return word;
    }

    string ans;
    for (uint32_t i = 0; i < length; i++) {
        ans = max(ans, word.substr(i, min(length - i, length - static_cast<uint32_t>(numFriends) + 1)));
    }
    return ans;
}
