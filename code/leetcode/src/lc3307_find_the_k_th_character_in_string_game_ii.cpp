/*
 * Time : 2025-07-03 15:31:31
 * URL  : https://leetcode.cn/problems/find-the-k-th-character-in-string-game-ii/description/
 */
#include "lc3307_find_the_k_th_character_in_string_game_ii.h"

#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

char LC3307_FindTheKThCharacterInStringGameII::kthCharacter(long long k, std::vector<int>& operations)
{
    int32_t optCnt = 0;

    for (size_t idx = operations.size() - 1; idx >= 0 && idx < operations.size(); idx--) {
        if (idx < 63 && k > (1LL << idx)) {
            k -= (1LL << idx);
            optCnt += operations[idx];
        }
    }

    return static_cast<char>('a' + optCnt % 26);
}
