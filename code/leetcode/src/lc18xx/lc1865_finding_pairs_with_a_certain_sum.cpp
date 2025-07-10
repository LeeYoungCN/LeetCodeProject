/*
 * Time : 2025-07-06 08:38:55
 * URL  :
 * https://leetcode.cn/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06
 */
#include "lc18xx/lc1865_finding_pairs_with_a_certain_sum.h"

#include <cstdint>
#include <map>
#include <vector>

using namespace std;

void LC1865_FindingPairsWithACertainSum::FindSumPairs(vector<int>& nums1, vector<int>& nums2)
{
    m_nums2 = nums2;
    for (const auto& n : nums1) {
        m_nums1Map[n]++;
    }

    for (const auto& n : nums2) {
        m_nums2Map[n]++;
    }
}

void LC1865_FindingPairsWithACertainSum::add(int index, int val)
{
    int32_t oldVal = m_nums2[static_cast<uint32_t>(index)];
    m_nums2Map[oldVal]--;
    m_nums2[static_cast<uint32_t>(index)] += val;
    m_nums2Map[m_nums2[static_cast<uint32_t>(index)]]++;
}

int LC1865_FindingPairsWithACertainSum::count(int tot)
{
    int32_t ans = 0;
    int32_t minN2 = m_nums2Map.begin()->first;
    for (const auto& [n1, cnt] : m_nums1Map) {
        if (n1 + minN2 > tot) {
            break;
        }
        int32_t target = tot - n1;
        auto it = m_nums2Map.find(target);
        if (it != m_nums2Map.end()) {
            ans += it->second * cnt;
        }
    }
    return ans;
}
