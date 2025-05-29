// https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-questionURL_STRenvId=2025-05-18
#ifndef LC1931_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H
#define LC1931_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H

#include <vector>

namespace f1 {
class LC1931_PaintingAGridWithThreeDifferentColors {
public:
    int colorTheGrid(int m, int n);

private:
    bool isValidColor(unsigned int color, std::vector<unsigned int> &colorGrid);

    unsigned int m_rowCnt;
    unsigned int m_colCnt;
};
}  // namespace f1

namespace f2 {
class LC1931_PaintingAGridWithThreeDifferentColors {
public:
    int colorTheGrid(int m, int n);

private:
    bool isValidColor(unsigned int color);
    bool isAdjColor(unsigned int color1, unsigned int color2);

private:
    unsigned int m_rowCnt;
    unsigned int m_colCnt;
};
}  // namespace f2

#endif  // LC1931_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H
