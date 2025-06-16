/*
 * Time : 2025-06-16 16:45:34
 * URL  : https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#ifndef LC0074_SEARCH_A_2D_MATRIX_H
#define LC0074_SEARCH_A_2D_MATRIX_H

#include <vector>

class LC0074_SearchA2dMatrix {
public:
    LC0074_SearchA2dMatrix() = default;
    virtual ~LC0074_SearchA2dMatrix() = default;
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);
};

#endif  // LC0074_SEARCH_A_2D_MATRIX_H
