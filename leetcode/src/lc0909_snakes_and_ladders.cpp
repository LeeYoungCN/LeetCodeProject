/*
 * Time : 2025-05-31 00:34:07
 * URL  : https://leetcode.cn/problems/snakes-and-ladders/description/?envType=daily-questionURL_STRenvId=2025-05-31
 */
#include "lc0909_snakes_and_ladders.h"

#include <cstdint>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

namespace {
constexpr uint32_t MIN_STEP = 1;
constexpr uint32_t MAX_STEP = 6;
}  // namespace

int LC0909_SnakesAndLadders_Path::snakesAndLadders(vector<vector<int>>& board)
{
    const auto n = static_cast<uint32_t>(board.size());
    const uint32_t target = n * n;
    vector<int32_t> path(target + 1, 0);

    for (uint32_t i = 0, idx = 1; i < n; i++) {
        const uint32_t x = n - i - 1;
        for (uint32_t j = 0; j < n; j++) {
            uint32_t y = j;
            if (i % 2 == 1) {
                y = n - j - 1;
            }
            path[idx] = board[x][y];
            idx++;
        }
    }

    vector<uint32_t> distance(target + 1, 0);
    vector<bool> visitor(target + 1, false);
    queue<uint32_t> stepQueue;

    stepQueue.push(1);
    visitor[1] = true;

    while (!stepQueue.empty()) {
        const uint32_t curr = stepQueue.front();
        stepQueue.pop();

        for (uint32_t i = MIN_STEP; i <= MAX_STEP; i++) {
            uint32_t next = curr + i;
            const uint32_t dist = distance[curr] + 1;

            if (next == target) {
                return static_cast<int32_t>(dist);
            }

            if (path[next] > 0) {
                next = static_cast<uint32_t>(path[next]);
            }

            if (next == target) {
                return static_cast<int32_t>(dist);
            }

            if (!visitor[next] == true) {
                visitor[next] = true;
                stepQueue.push(next);
                distance[next] = dist;
            }
        }
    }
    return -1;
}

int LC0909_SnakesAndLadders_XY::snakesAndLadders(vector<vector<int>>& board)
{
    const auto n = static_cast<uint32_t>(board.size());
    const auto target = static_cast<uint32_t>(n * n);

    const function<int32_t(uint32_t)> getVal = [&](const uint32_t idx) -> int32_t {
        const uint32_t num = idx - 1;
        const uint32_t layer = num / n;
        const uint32_t x = n - 1 - layer;
        uint32_t y = num % n;
        if (layer % 2 == 1) {
            y = n - y - 1;
        }
        return board[x][y];
    };

    vector<uint32_t> distance(target + 1, 0);
    vector<bool> visitor(target + 1, false);
    queue<uint32_t> stepQueue;

    stepQueue.push(1);
    visitor[1] = true;
    while (!stepQueue.empty()) {
        const uint32_t curr = stepQueue.front();
        stepQueue.pop();

        for (uint32_t i = MIN_STEP; i <= MAX_STEP; i++) {
            uint32_t next = curr + i;
            const uint32_t dist = distance[curr] + 1;

            if (next == target) {
                return static_cast<int32_t>(dist);
            }
            if (const int32_t val = getVal(next); val > 0) {
                next = static_cast<uint32_t>(val);
            }

            if (next == target) {
                return static_cast<int32_t>(dist);
            }

            if (visitor[next] == true) {
                continue;
            }
            visitor[next] = true;
            stepQueue.push(next);
            distance[next] = dist;
        }
    }
    return -1;
}
