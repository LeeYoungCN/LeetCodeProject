/*
 * Time : 2025-06-02 23:56:29
 * URL  : https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/description/
 */

#include "lc3186_maximum_total_damage_with_spell_casting.h"

#include <algorithm>
#include <cstdint>
#include <unordered_map>
#include <vector>

using namespace std;

long long LC3186_MaximumTotalDamageWithSpellCasting::maximumTotalDamage(std::vector<int>& power)
{
    unordered_map<int32_t, int64_t> numMap;
    for (int32_t p : power) {
        numMap[p] += p;
    }

    uint32_t numCnt = (uint32_t)numMap.size();

    vector<pair<int32_t, int64_t>> numVec;
    numVec.reserve(numCnt);
    for (pair<int32_t, int64_t> p : numMap) {
        numVec.push_back(p);
    }
    sort(numVec.begin(), numVec.end());

    vector<int64_t> dp(numCnt, 0);
    dp[0] = numVec[0].second;

    for (uint32_t i = 1; i < numCnt; i++) {
        int64_t dpj = 0;

        for (int32_t j = (int32_t)i - 1; j >= 0; j--) {
            if (numVec[(uint32_t)j].first < numVec[i].first - 2) {
                dpj = dp[(uint32_t)j];
                break;
            }
        }

        dp[i] = max(dp[i - 1], dpj + numVec[i].second);
    }

    return dp.back();
}
