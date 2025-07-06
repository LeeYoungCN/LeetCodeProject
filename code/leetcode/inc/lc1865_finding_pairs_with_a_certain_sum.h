/*
 * Time : 2025-07-06 08:38:55
 * URL  :
 * https://leetcode.cn/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06
 */
#ifndef LC1865_FINDING_PAIRS_WITH_A_CERTAIN_SUM_H
#define LC1865_FINDING_PAIRS_WITH_A_CERTAIN_SUM_H

#include <map>
#include <vector>

class LC1865_FindingPairsWithACertainSum {
public:
    LC1865_FindingPairsWithACertainSum() = default;
    virtual ~LC1865_FindingPairsWithACertainSum() = default;
    void FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2);
    void add(int index, int val);
    int count(int tot);

private:
    std::map<int, int> m_nums1Map;
    std::vector<int> m_nums2;
    std::map<int, int> m_nums2Map;
};

#endif  // LC1865_FINDING_PAIRS_WITH_A_CERTAIN_SUM_H
