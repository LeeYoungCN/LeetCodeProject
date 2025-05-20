// https://leetcode.cn/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17
#ifndef LC0075_SORT_COLORS_H
#define LC0075_SORT_COLORS_H
#include <vector>

class LC0075_SortColors {
    public:
        void sortColors(std::vector<int>& nums);
    private:
        void sort(std::vector<int> &nums, uint32_t start, uint32_t length);
        void merge(std::vector<int> &nums, uint32_t lStart, uint32_t lLen, uint32_t rStart, uint32_t rLen);
};

#endif // LC0075_SORT_COLORS_H
