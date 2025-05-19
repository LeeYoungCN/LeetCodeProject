// https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-questionURL_STRenvId=2025-05-18
#ifndef LC1931_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H
#define LC1931_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H
#include <vector>

namespace f1 {
    class Lc1931_PaintingAGridWithThreeDifferentColors {
        public:
            int colorTheGrid(int m, int n);
        private:
            bool isValidColor(uint32_t color, std::vector<uint32_t> &colorGrid);

            uint32_t m_rowCnt;
            uint32_t m_colCnt;
    };
}

namespace f2 {
    class Lc1931_PaintingAGridWithThreeDifferentColors {
        public:
            int colorTheGrid(int m, int n);
        private:
            bool isValidColor(uint32_t color);
            bool isAdjColor(uint32_t color1, uint32_t color2);

        private:
            uint32_t m_rowCnt;
            uint32_t m_colCnt;
    };
}

#endif // LC1931_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H