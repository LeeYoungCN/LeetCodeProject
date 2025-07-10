/*
 * Time : 2025-06-16 16:45:34
 * URL  : https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#include "lc00xx/lc0074_search_a_2d_matrix.h"

#include <cstdint>
#include <vector>

using namespace std;

bool LC0074_SearchA2dMatrix::searchMatrix(vector<vector<int>> &matrix, int target)
{
    const auto row = static_cast<uint32_t>(matrix.size());
    const auto col = static_cast<uint32_t>(matrix[0].size());

    uint32_t left = 0;
    uint32_t right = row * col;

    while (left < right) {
        uint32_t curr = (left + right) / 2;
        int32_t n = matrix[curr / col][curr % col];
        if (target == n) {
            return true;
        }
        if (n < target) {
            left = curr + 1;
        } else {
            right = curr;
        }
    }
    return false;
}
