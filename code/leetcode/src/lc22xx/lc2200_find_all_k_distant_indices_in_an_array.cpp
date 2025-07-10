/*
 * Time : 2025-06-24 00:25:16
 * URL  :
 * https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/description/?envType=daily-question&envId=2025-06-24
 */
#include "lc22xx/lc2200_find_all_k_distant_indices_in_an_array.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

std::vector<int> LC2200_FindAllKDistantIndicesInAnArray::findKDistantIndices(std::vector<int>& nums, int key, int k)
{
    const auto length = static_cast<uint32_t>(nums.size());
    vector<int32_t> ans;
    ans.reserve(length);

    for (uint32_t i = 0; i < length; ++i) {
        if (nums[i] != key) {
            continue;
        }

        auto mid = static_cast<int32_t>(i);
        int32_t start = max({mid - k, 0, (ans.empty() ? 0 : ans.back() + 1)});
        for (int32_t j = start; j < min(mid + k + 1, static_cast<int32_t>(length)); j++) {
            ans.push_back(j);
        }
    }

    return ans;
}
