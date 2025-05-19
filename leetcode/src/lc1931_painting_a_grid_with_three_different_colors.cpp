// https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-questionURL_STRenvId=2025-05-18
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include "lc1931_painting_a_grid_with_three_different_colors.h"

using namespace std;

const uint32_t COLOR_CNT = 3;
const uint32_t MOD = 1000000007;

int Lc1931_PaintingAGridWithThreeDifferentColors::colorTheGrid(int m, int n)
{
    const uint32_t colCnt = m;
    const uint32_t rowCnt = n;
    map<uint32_t, vector<uint32_t>> validColorMap;
    const uint32_t maxColorCnt = pow(COLOR_CNT, colCnt);

    for (uint32_t i = 0; i < maxColorCnt; i++) {
        uint32_t color = i;
        vector<uint32_t> colorGrid(colCnt, 0);
        // index to color group.
        for (uint32_t i = 0; i < colCnt && color > 0; i++) {
            colorGrid[i] = color % COLOR_CNT;
            color = color / COLOR_CNT;
        }
        // check color group is valid.
        bool isValid = true;
        for (uint32_t i = 1; i < colCnt && isValid; i++) {
            isValid = (colorGrid[i-1] != colorGrid[i]);
        }
        // save valid color group.
        if (isValid) {
            validColorMap.emplace(i, colorGrid);
        }
    }

    map<uint32_t, vector<uint32_t>> adjColorMap;
    for (const auto &[color1, colorGroup1] : validColorMap) {
        for (const auto &[color2, colorGroup2] : validColorMap) {
            bool isAdj = true;
            for (uint32_t i = 0; i < colCnt && isAdj; i++) {
                isAdj = (colorGroup1[i] != colorGroup2[i]);
            }
            if (isAdj) {
                adjColorMap[color1].push_back(color2);
            }
        }
    }

    vector<vector<uint32_t>> dp(rowCnt, vector<uint32_t>(maxColorCnt, 0));

    for (const auto &[color, _] : adjColorMap) {
        dp[0][color] = 1;
    }

    for (uint32_t i = 1; i < rowCnt; i++) {
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
        result += dp[rowCnt - 1][i];
        if (result >= MOD) {
            result -= MOD;
        }
    }
    return result;
}

