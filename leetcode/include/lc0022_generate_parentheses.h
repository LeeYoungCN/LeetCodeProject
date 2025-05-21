/*
 * Time : 2025-05-19 16:35:29
 * URL  : https://leetcode.cn/problems/generate-parentheses/description/?envType=daily-questionURL_STRenvId=2025-05-18
 */

#ifndef LC0022_GENERATE_PARENTHESES_H
#define LC0022_GENERATE_PARENTHESES_H
#include <vector>
#include <string>

class LC0022_GenerateParentheses {
    public:
        virtual std::vector<std::string> generateParenthesis(int n) = 0;
        LC0022_GenerateParentheses() {};
        virtual ~LC0022_GenerateParentheses() {};
    protected:
        bool isValidStr(const std::string &str);
};


class LC0022_GenerateParentheses_Num : public LC0022_GenerateParentheses {
    public:
        std::vector<std::string> generateParenthesis(int n) override;
    private:
        void generateStrByLoop(uint32_t strLen, std::vector<std::string> &result);
        void num2Str(uint32_t num, uint32_t strLen, std::string &current);
};

class LC0022_GenerateParentheses_Itr1 : public LC0022_GenerateParentheses {
    public:
        std::vector<std::string> generateParenthesis(int n);
    private:
        // void generateStrByItr(uint32_t strLen, std::vector<std::string> &result);
        void iter2Str(std::string &curr, uint32_t strLen, std::vector<std::string> &result);
};

class LC0022_GenerateParentheses_Itr2 : public LC0022_GenerateParentheses {
    public:
        std::vector<std::string> generateParenthesis(int n);
    private:
        void generateStrByItr(std::string &curr, std::vector<std::string> &result,
                              uint32_t leftNum, uint32_t rightNum, uint32_t maxCnt);
};


#endif // LC0022_GENERATE_PARENTHESES_H
 