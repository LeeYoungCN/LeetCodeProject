/*
 * Time : 2025-06-27 17:46:05
 * URL  : https://leetcode.cn/problems/permutations/description/
 */
#include "lc0xxx/lc00xx/lc004x/lc0046_permutations.h"

#include <algorithm>
#include <cmath>
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

void dfs(const vector<int32_t>& nums, vector<int32_t>& permution, vector<bool>& visitor, vector<vector<int32_t>>& ans)
{
    if (permution.size() == nums.size()) {
        ans.emplace_back(permution);
    }

    for (uint32_t i = 0; i < nums.size(); ++i) {
        if (!visitor[i]) {
            visitor[i] = true;
            permution.push_back(nums[i]);
            dfs(nums, permution, visitor, ans);
            visitor[i] = false;
            permution.pop_back();
        }
    }
}

vector<vector<int>> LC0046_Permutations::permute(vector<int>& nums)
{
    vector<vector<int32_t>> ans;
    vector<bool> visitor(nums.size(), false);
    vector<int32_t> permution;

    permution.reserve(nums.size());
    dfs(nums, permution, visitor, ans);
    return ans;
}
