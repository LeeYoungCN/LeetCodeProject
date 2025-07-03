/*
 * Time : 2025-07-03 14:46:38
 * URL  :
 * https://leetcode.cn/problems/find-the-k-th-character-in-string-game-i/description/?envType=daily-question&envId=2025-07-03
 */
#include "lc3304_find_the_k_th_character_in_string_game_i.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
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

char LC3304_FindTheKThCharacterInStringGameI::kthCharacter(int32_t k)
{
    const auto K = static_cast<size_t>(k);
    string str = "a";
    str.reserve(K);
    while (str.size() < K) {
        size_t j = str.size();
        str += str;
        for (; j < str.size(); ++j) {
            str[j] = (str[j] == 'z' ? 'a' : static_cast<char>(str[j] + 1));
        }
    }

    return str[K - 1];
}
