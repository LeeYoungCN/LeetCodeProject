// https://leetcode.cn/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17
#ifndef LC0075_SORT_COLORS_H
#define LC0075_SORT_COLORS_H

#include <vector>

class LC0075_SortColors {
public:
    void sortColors(std::vector<int> &nums);

private:
    void sort(std::vector<int> &nums, unsigned int start, unsigned int length);
    void merge(std::vector<int> &nums, unsigned int lStart, unsigned int lLen, unsigned int rStart, unsigned int rLen);
};

#endif  // LC0075_SORT_COLORS_H
