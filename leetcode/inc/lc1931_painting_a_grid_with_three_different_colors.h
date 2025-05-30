// https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-questionURL_STRenvId=2025-05-18
#ifndef LC1931_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H
#define LC1931_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H

#include <vector>

class LC1931_PaintingAGridWithThreeDifferentColors {
public:
    LC1931_PaintingAGridWithThreeDifferentColors() = default;
    virtual ~LC1931_PaintingAGridWithThreeDifferentColors() = default;
    virtual int colorTheGrid(int m, int n) = 0;

protected:
    unsigned int m_rowCnt;
    unsigned int m_colCnt;
};

class LC1931_PaintingAGridWithThreeDifferentColors_Grid : public LC1931_PaintingAGridWithThreeDifferentColors {
public:
    LC1931_PaintingAGridWithThreeDifferentColors_Grid() = default;
    virtual ~LC1931_PaintingAGridWithThreeDifferentColors_Grid() override = default;
    int colorTheGrid(int m, int n) override;

private:
    bool isValidColor(unsigned int color, std::vector<unsigned int> &colorGrid);
};

class LC1931_PaintingAGridWithThreeDifferentColors_Number : public LC1931_PaintingAGridWithThreeDifferentColors {
public:
    LC1931_PaintingAGridWithThreeDifferentColors_Number() = default;
    virtual ~LC1931_PaintingAGridWithThreeDifferentColors_Number() override = default;
    int colorTheGrid(int m, int n) override;

private:
    bool isValidColor(unsigned int color);
    bool isAdjColor(unsigned int color1, unsigned int color2);
};

#endif  // LC1931_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H
