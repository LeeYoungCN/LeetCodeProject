/*
 * Time : 2025-06-02 00:20:13
 * URL  : https://leetcode.cn/problems/candy/description/?envType=daily-questionURL_STRenvId=2025-06-02
 */
#ifndef LC0135_CANDY_H
#define LC0135_CANDY_H

#include <vector>

class LC0135_Candy {
public:
    LC0135_Candy() = default;
    virtual ~LC0135_Candy() = default;
    virtual int candy(std::vector<int>& ratings) = 0;
};

class LC0135_Candy_Stack : public LC0135_Candy {
public:
    LC0135_Candy_Stack() = default;
    virtual ~LC0135_Candy_Stack() override = default;
    int candy(std::vector<int>& ratings) override;
};

class LC0135_Candy_TwoTraverse : public LC0135_Candy {
public:
    LC0135_Candy_TwoTraverse() = default;
    virtual ~LC0135_Candy_TwoTraverse() override = default;
    int candy(std::vector<int>& ratings) override;
};

class LC0135_Candy_OneTraverse : public LC0135_Candy {
public:
    LC0135_Candy_OneTraverse() = default;
    virtual ~LC0135_Candy_OneTraverse() override = default;
    int candy(std::vector<int>& ratings) override;
};

#endif  // LC0135_CANDY_H
