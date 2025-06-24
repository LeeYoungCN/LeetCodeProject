/*
 * Time : 2025-06-16 21:43:13
 * URL  :
 * https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#ifndef LC0081_SEARCH_IN_ROTATED_SORTED_ARRAY_II_H
#define LC0081_SEARCH_IN_ROTATED_SORTED_ARRAY_II_H

#include <vector>

class LC0081_SearchInRotatedSortedArrayII {
public:
    LC0081_SearchInRotatedSortedArrayII() = default;
    virtual ~LC0081_SearchInRotatedSortedArrayII() = default;
    virtual bool search(std::vector<int>& nums, int target) = 0;
};

class LC0081_SearchInRotatedSortedArrayII_DFS : public LC0081_SearchInRotatedSortedArrayII {
public:
    LC0081_SearchInRotatedSortedArrayII_DFS() = default;
    ~LC0081_SearchInRotatedSortedArrayII_DFS() override = default;
    bool search(std::vector<int>& nums, int target) final;

private:
    bool dfs(const std::vector<int>& nums, int target, unsigned int left, unsigned int right);
    bool isLeftArea(const std::vector<int>& nums, int n);
};

class LC0081_SearchInRotatedSortedArrayII_Loop : public LC0081_SearchInRotatedSortedArrayII {
public:
    LC0081_SearchInRotatedSortedArrayII_Loop() = default;
    ~LC0081_SearchInRotatedSortedArrayII_Loop() override = default;
    bool search(std::vector<int>& nums, int target) final;
};

#endif  // LC0081_SEARCH_IN_ROTATED_SORTED_ARRAY_II_H
