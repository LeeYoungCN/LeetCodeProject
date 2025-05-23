/*
 * Time     : 2025-05-23 01:03:47
 * URL      : https://leetcode.cn/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-questionURL_STRenvId=2025-05-23
 * Problem  : 给你一棵 n 个节点的无向树，节点从 0 到 n - 1 编号。树以长度为 n - 1 下标从 0 开始的二维整数数组 edges 的形式给你，
 *            其中 edges[i] = [ui, vi] 表示树中节点 ui 和 vi 之间有一条边。
 *            同时给你一个 正 整数 k 和一个长度为 n 下标从 0 开始的 非负 整数数组 nums ，其中 nums[i] 表示节点 i 的 价值 。
 *            Alice 想 最大化 树中所有节点价值之和。为了实现这一目标，Alice 可以执行以下操作任意次（包括 0 次）：
 *            选择连接节点 u 和 v 的边 [u, v]，并将它们的值更新为：
 *            nums[u] = nums[u] XOR k
 *            nums[v] = nums[v] XOR k
 *            请你返回 Alice 通过执行以上操作任意次后，可以得到所有节点价值之和的最大值 。
 */
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <functional>
#include "lc3068_find_the_maximum_sum_of_node_values.h"

// 一个值 a 异或偶数次 k 值仍为 a。
// 对于树上任意两点，存在一条路径，对路径上的每一条边进行操作，除了路径的起点和终点进行了一次异或，剩下的所有点都进行了两次异或，值不变。也就是等价于我们可以对树上任意两点进行一次异或操作。

using namespace std;

long long LC3068_FindTheMaximumSumOfNodeValues_Greedy::maximumValueSum(vector<int> &nums, int k,
                                                                       vector<vector<int> > &edges)
{
    const uint32_t length = nums.size();

    int64_t ret = 0;
    vector<int64_t> diffArray(length, 0);

    for (uint32_t i = 0; i < length; i++) {
        diffArray[i] = (nums[i] ^ k) - nums[i];
        ret += nums[i];
    }

    sort(diffArray.begin(), diffArray.end(), greater<int>());
    // 每次选两个点, 尽量选大的。
    for (uint32_t i = 1; i < length; i += 2) {
        const int64_t sum = diffArray[i] + diffArray[i - 1];
        if (sum >= 0) {
            ret += sum;
        } else {
            break;
        }
    }
    return ret;
}

long long LC3068_FindTheMaximumSumOfNodeValues_DFS::maximumValueSum(std::vector<int> &nums, int k,
                                                                    std::vector<std::vector<int> > &edges)
{
    uint32_t length = nums.size();
    
    return 0;
}
