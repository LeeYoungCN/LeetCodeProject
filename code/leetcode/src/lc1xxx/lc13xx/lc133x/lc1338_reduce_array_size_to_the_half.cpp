/*
 * Time : 2025-06-01 23:45:39
 * URL  : https://leetcode.cn/problems/reduce-array-size-to-the-half/
 */
#include "lc1xxx/lc13xx/lc133x/lc1338_reduce_array_size_to_the_half.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <unordered_map>
#include <vector>

using namespace std;

int LC1338_ReduceArraySizeToTheHalf::minSetSize(std::vector<int>& arr)
{
    unordered_map<int32_t, int32_t> numMap;
    for (int32_t n : arr) {
        numMap[n]++;
    }
    const auto numTypeCnt = static_cast<uint32_t>(numMap.size());
    vector<int32_t> numCntVec;
    numCntVec.reserve(numTypeCnt);

    for (const auto& [num, cnt] : numMap) {
        numCntVec.push_back(cnt);
    }

    sort(numCntVec.begin(), numCntVec.end(), greater<>());

    int32_t half = static_cast<int32_t>(arr.size()) / 2;

    for (uint32_t i = 0; i < numTypeCnt; i++) {
        half -= numCntVec[i];
        if (half <= 0) {
            return static_cast<int32_t>(i) + 1;
        }
    }
    return static_cast<int32_t>(numTypeCnt);
}
