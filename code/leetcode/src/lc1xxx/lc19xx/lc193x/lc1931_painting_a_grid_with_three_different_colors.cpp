// https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-questionURL_STRenvId=2025-05-18
#include "lc1xxx/lc19xx/lc193x/lc1931_painting_a_grid_with_three_different_colors.h"

#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

using namespace std;

const uint32_t COLOR_CNT = 3;
const uint32_t MOD = 1000000007;

bool LC1931_PaintingAGridWithThreeDifferentColors_Grid::isValidColor(uint32_t color, vector<uint32_t> &colorGrid)
{
    for (uint32_t i = 0; i < m_colCnt && color > 0; i++) {
        colorGrid[i] = color % COLOR_CNT;
        color = color / COLOR_CNT;
    }
    // check color group is valid.
    bool isValid = true;
    for (uint32_t i = 1; i < m_colCnt && isValid; i++) {
        isValid = (colorGrid[i - 1] != colorGrid[i]);
    }
    return isValid;
}

int LC1931_PaintingAGridWithThreeDifferentColors_Grid::colorTheGrid(int m, int n)
{
    m_colCnt = static_cast<uint32_t>(m);
    m_rowCnt = static_cast<uint32_t>(n);
    std::map<uint32_t, std::vector<uint32_t>> validColorMap;
    const auto maxColorCnt = static_cast<uint32_t>(pow(COLOR_CNT, m_colCnt));

    for (uint32_t color = 0; color < maxColorCnt; color++) {
        vector<uint32_t> colorGrid(m_colCnt, 0);

        if (isValidColor(color, colorGrid)) {
            validColorMap.emplace(color, colorGrid);
        }
    }

    map<uint32_t, vector<uint32_t>> adjColorMap;
    for (const auto &[color1, colorGrid1] : validColorMap) {
        for (const auto &[color2, colorGrid2] : validColorMap) {
            bool isAdj = true;
            for (uint32_t i = 0; i < m_colCnt && isAdj; i++) {
                isAdj = (colorGrid1[i] != colorGrid2[i]);
            }
            if (isAdj) {
                adjColorMap[color1].push_back(color2);
            }
        }
    }

    vector<vector<uint32_t>> dp(m_rowCnt, vector<uint32_t>(maxColorCnt, 0));

    for (const auto &[color, _] : validColorMap) {
        dp[0][color] = 1;
    }

    for (uint32_t i = 1; i < m_rowCnt; i++) {
        for (const auto &[color1, _] : validColorMap) {
            for (const auto color2 : adjColorMap[color1]) {
                dp[i][color1] += dp[i - 1][color2];
                if (dp[i][color1] >= MOD) {
                    dp[i][color1] -= MOD;
                }
            }
        }
    }

    uint32_t result = 0;
    for (uint32_t i = 0; i < maxColorCnt; i++) {
        result += dp[m_rowCnt - 1][i];
        if (result >= MOD) {
            result -= MOD;
        }
    }
    return static_cast<int32_t>(result);
}

bool LC1931_PaintingAGridWithThreeDifferentColors_Number::isValidColor(uint32_t color)
{
    if (m_colCnt == 1) {
        return true;
    }

    uint32_t prev = color % COLOR_CNT;
    color /= COLOR_CNT;

    // check color group is valid.
    bool isValid = true;

    for (uint32_t i = 1; i < m_colCnt && isValid; i++) {
        uint32_t curr = color % COLOR_CNT;
        color /= COLOR_CNT;
        isValid = (curr != prev);
        prev = curr;
    }

    return isValid;
}

bool LC1931_PaintingAGridWithThreeDifferentColors_Number::isAdjColor(uint32_t color1, uint32_t color2)
{
    bool isAdj = true;
    for (uint32_t i = 0; i < m_colCnt && isAdj; ++i) {
        isAdj = (color1 % COLOR_CNT != color2 % COLOR_CNT);
        color1 /= COLOR_CNT;
        color2 /= COLOR_CNT;
    }
    return isAdj;
}

int LC1931_PaintingAGridWithThreeDifferentColors_Number::colorTheGrid(int m, int n)
{
    m_colCnt = static_cast<uint32_t>(m);
    m_rowCnt = static_cast<uint32_t>(n);
    const auto maxColorCnt = static_cast<uint32_t>(pow(COLOR_CNT, m_colCnt));

    vector<uint32_t> validColorArray;
    validColorArray.reserve(maxColorCnt);
    for (uint32_t color = 0; color < maxColorCnt; color++) {
        // save valid color group.
        if (isValidColor(color)) {
            validColorArray.push_back(color);
        }
    }

    auto validColorCnt = static_cast<uint32_t>(validColorArray.size());
    vector<vector<uint32_t>> adjColorMap(validColorCnt);

    for (uint32_t colorIdx1 = 0; colorIdx1 < validColorCnt; ++colorIdx1) {
        for (uint32_t colorIdx2 = 0; colorIdx2 < validColorCnt; ++colorIdx2) {
            if (isAdjColor(validColorArray[colorIdx1], validColorArray[colorIdx2])) {
                adjColorMap[colorIdx1].push_back(colorIdx2);
            }
        }
    }

    vector<vector<uint32_t>> dp(m_rowCnt, vector<uint32_t>(validColorCnt, 0));

    for (uint32_t colorIndex = 0; colorIndex < validColorCnt; ++colorIndex) {
        dp[0][colorIndex] = 1;
    }

    for (uint32_t i = 1; i < m_rowCnt; i++) {
        for (uint32_t colorIdx1 = 0; colorIdx1 < validColorCnt; ++colorIdx1) {
            for (const uint32_t colorIdx2 : adjColorMap[colorIdx1]) {
                dp[i][colorIdx1] += dp[i - 1][colorIdx2];
                if (dp[i][colorIdx1] >= MOD) {
                    dp[i][colorIdx1] -= MOD;
                }
            }
        }
    }
    uint32_t result = 0;
    for (uint32_t i = 0; i < validColorCnt; i++) {
        result += dp[m_rowCnt - 1][i];
        if (result >= MOD) {
            result -= MOD;
        }
    }
    return static_cast<int32_t>(result);
}
