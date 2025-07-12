/*
 * Time : 2025-06-22 18:18:39
 * URL  : https://leetcode.cn/problems/decode-ways/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#ifndef LC0091_DECODE_WAYS_H
#define LC0091_DECODE_WAYS_H

#include <string>

class LC0091_DecodeWays {
public:
    LC0091_DecodeWays() = default;
    virtual ~LC0091_DecodeWays() = default;
    virtual int numDecodings(std::string s) = 0;
};

class LC0091_DecodeWays_V1 : public LC0091_DecodeWays {
public:
    LC0091_DecodeWays_V1() = default;
    ~LC0091_DecodeWays_V1() override = default;
    int numDecodings(std::string s) override;
};

class LC0091_DecodeWays_V2 : public LC0091_DecodeWays {
public:
    LC0091_DecodeWays_V2() = default;
    ~LC0091_DecodeWays_V2() override = default;
    int numDecodings(std::string s) override;
};

#endif  // LC0091_DECODE_WAYS_H
