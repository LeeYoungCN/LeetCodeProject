/*
 * Time : 2025-06-06 15:36:48
 * URL  : https://leetcode.cn/problems/find-original-array-from-doubled-array/description/
 */
#include "lc2007_find_original_array_from_doubled_array.h"

#include <cstdint>
#include <functional>
#include <map>
#include <vector>

using namespace std;

vector<int32_t> LC2007_FindOriginalArrayFromDoubledArray_Map::findOriginalArray(vector<int32_t> &changed)
{
    const auto length = static_cast<uint32_t>(changed.size());
    if (length % 2 != 0) {
        return {};
    }

    map<int32_t, uint32_t, less<>> changeMap;
    for (const int32_t n : changed) {
        changeMap[n]++;
    }

    vector<int32_t> ans;
    ans.reserve(length / 2);

    if (changeMap.find(0) != changeMap.end()) {
        if (changeMap[0] % 2 != 0) {
            return {};
        }
        ans.insert(ans.end(), changeMap[0] / 2, 0);
        changeMap.erase(0);
    }

    for (const auto [num, cnt] : changeMap) {
        if (cnt == 0) {
            continue;
        }

        const int32_t target = num * 2;

        if (const auto it = changeMap.find(target); it == changeMap.end() || it->second < cnt) {
            return {};
        }

        ans.insert(ans.end(), cnt, num);
        changeMap[target] -= cnt;
        changeMap[num] = 0;
    }

    return ans;
}
