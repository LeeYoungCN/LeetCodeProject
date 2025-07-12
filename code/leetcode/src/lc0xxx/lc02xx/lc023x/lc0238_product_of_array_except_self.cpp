/*
 * Time : 2025-06-12 14:21:47
 * URL  :
 * https://leetcode.cn/problems/product-of-array-except-self/description/?envType=problem-list-v2URL_STRenvId=prefix-sum
 */
#include "lc0xxx/lc02xx/lc023x/lc0238_product_of_array_except_self.h"

#include <cstdint>
#include <vector>

using namespace std;

vector<int> LC0238_ProductOfArrayExceptSelf::productExceptSelf(vector<int>& nums)
{
    const auto length = static_cast<uint32_t>(nums.size());
    vector<int32_t> prefixSum(length, 1);
    vector<int32_t> suffixSum(length, 1);

    for (uint32_t i = 1; i < length; i++) {
        prefixSum[i] = prefixSum[i - 1] * nums[i - 1];
        uint32_t j = length - i - 1;
        suffixSum[j] = suffixSum[j + 1] * nums[j + 1];
    }

    vector<int32_t> ans(length, 0);
    for (uint32_t i = 0; i < length; i++) {
        ans[i] = prefixSum[i] * suffixSum[i];
    }

    return ans;
}
