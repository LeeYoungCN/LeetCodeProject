/*
 * Time : 2025-07-13 12:37:24
 * URL  :
 * https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/description/?envType=daily-question&envId=2025-07-13
 */
#include "lc2xxx/lc24xx/lc241x/lc2410_maximum_matching_of_players_with_trainers.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC2410_MaximumMatchingOfPlayersWithTrainers::matchPlayersAndTrainers(std::vector<int32_t>& players,
                                                                             std::vector<int32_t>& trainers)
{
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    size_t i = 0;
    for (size_t j = 0; i < players.size() && j < trainers.size(); j++) {
        if (players[i] <= trainers[j]) {
            i++;
        }
    }
    return static_cast<int32_t>(i);
}
