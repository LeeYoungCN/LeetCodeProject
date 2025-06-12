/*
 * Time : 2025-05-31 00:34:07
 * URL  : https://leetcode.cn/problems/snakes-and-ladders/description/?envType=daily-questionURL_STRenvId=2025-05-31
 */
#ifndef LC0909_SNAKES_AND_LADDERS_H
#define LC0909_SNAKES_AND_LADDERS_H

#include <vector>

class LC0909_SnakesAndLadders {
public:
    LC0909_SnakesAndLadders() = default;
    virtual ~LC0909_SnakesAndLadders() = default;
    virtual int snakesAndLadders(std::vector<std::vector<int>>& board) = 0;
};

class LC0909_SnakesAndLadders_Path : public LC0909_SnakesAndLadders {
public:
    LC0909_SnakesAndLadders_Path() = default;
    ~LC0909_SnakesAndLadders_Path() override = default;
    int snakesAndLadders(std::vector<std::vector<int>>& board) final;
};

class LC0909_SnakesAndLadders_XY : public LC0909_SnakesAndLadders {
public:
    LC0909_SnakesAndLadders_XY() = default;
    ~LC0909_SnakesAndLadders_XY() override = default;
    int snakesAndLadders(std::vector<std::vector<int>>& board) final;
};

#endif  // LC0909_SNAKES_AND_LADDERS_H
