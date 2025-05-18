// https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-questionURL_STRenvId=2025-05-18
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include "lc1931_painting_a_grid_with_three_different_colors.h"

using namespace std;

int Lc1931_PaintingAGridWithThreeDifferentColors::colorTheGrid(int m, int n)
{
    const uint32_t COLOR_CNT = 3;
    const uint32_t MOD = 1000000007;
    const uint32_t colCnt = m;
    const uint32_t rowCnt = n;
    map<uint32_t, vector<uint32_t>> validColorMap;
    const uint32_t maxColorIdx = pow(COLOR_CNT, colCnt);

    for (uint32_t i = 0; i < maxColorIdx; i++) {
        uint32_t index = i;
        vector<uint32_t> colorGroup(colCnt, 0);
        // index to color group.
        for (uint32_t i = 0; i < colCnt && index > 0; i++) {
            colorGroup[i] = index % COLOR_CNT;
            index = index / COLOR_CNT;
        }
        // check color group is valid.
        bool isValid = true;
        for (uint32_t i = 1; i < colCnt && isValid; i++) {
            isValid = (colorGroup[i-1] != colorGroup[i]);
        }
        // save valid color group.
        if (isValid) {
            validColorMap.emplace(i, colorGroup);
        }
    }

    map<uint32_t, vector<uint32_t>> adjColorMap;
    for (const auto &[index1, colorGroup1] : validColorMap) {
        for (const auto &[index2, colorGroup2] : validColorMap) {
            bool isAdj = true;
            for (uint32_t i = 0; i < colCnt && isAdj; i++) {
                isAdj = (colorGroup1[i] != colorGroup2[i]);
            }
            if (isAdj) {
                adjColorMap[index1].push_back(index2);
            }
        }
    }

    vector<vector<uint32_t>> dp(rowCnt, vector<uint32_t>(maxColorIdx, 0));

    for (const auto &[index, _] : adjColorMap) {
        dp[0][index] = 1;
    }

    for (uint32_t i = 1; i < rowCnt; i++) {
        for (const auto &[index1, _] : validColorMap) {
            for (const auto index2 : adjColorMap[index1]) {
                dp[i][index1] += dp[i - 1][index2];
                if (dp[i][index1] >= MOD) {
                    dp[i][index1] -= MOD;
                }
            }
        }
    }
    uint32_t result = 0;
    for (uint32_t i = 0; i < maxColorIdx; i++) {
        result += dp[rowCnt - 1][i];
        if (result >= MOD) {
            result -= MOD;
        }
    }
    return result;
}

