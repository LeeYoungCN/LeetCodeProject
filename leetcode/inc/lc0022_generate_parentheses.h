/*
 * Time : 2025-05-19 16:35:29
 * URL  : https://leetcode.cn/problems/generate-parentheses/description/?envType=daily-questionURL_STRenvId=2025-05-18
 */

#ifndef LC0022_GENERATE_PARENTHESES_H
#define LC0022_GENERATE_PARENTHESES_H

#include <string>
#include <vector>

class LC0022_GenerateParentheses {
public:
    virtual std::vector<std::string> generateParenthesis(int n) = 0;
    LC0022_GenerateParentheses() = default;
    virtual ~LC0022_GenerateParentheses() = default;

protected:
    bool isValidStr(const std::string &str);
};

class LC0022_GenerateParentheses_Num : public LC0022_GenerateParentheses {
public:
    std::vector<std::string> generateParenthesis(int n) final;

private:
    void generateStrByLoop(unsigned int strLen, std::vector<std::string> &result);
    void num2Str(unsigned int num, unsigned int strLen, std::string &current);
};

class LC0022_GenerateParentheses_Itr1 : public LC0022_GenerateParentheses {
public:
    std::vector<std::string> generateParenthesis(int n) final;

private:
    void iter2Str(std::string &curr, unsigned int strLen, std::vector<std::string> &result);
};

class LC0022_GenerateParentheses_Itr2 : public LC0022_GenerateParentheses {
public:
    std::vector<std::string> generateParenthesis(int n) final;

private:
    void generateStrByItr(std::string &curr, std::vector<std::string> &result, unsigned int leftNum,
                          unsigned int rightNum, unsigned int maxCnt);
};

#endif  // LC0022_GENERATE_PARENTHESES_H
