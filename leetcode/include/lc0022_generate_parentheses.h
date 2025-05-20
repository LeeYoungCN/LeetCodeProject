/*
 * Time : 2025-05-19 16:35:29
 * URL  : https://leetcode.cn/problems/generate-parentheses/description/?envType=daily-questionURL_STRenvId=2025-05-18
 */

#ifndef LC0022_GENERATE_PARENTHESES_H
#define LC0022_GENERATE_PARENTHESES_H
#include <vector>
#include <string>

namespace method1 {
class LC0022_GenerateParentheses {
    public:
        std::vector<std::string> generateParenthesis(int n);
    private:
        bool isValidStr(const std::string &str);
        void generateStrByLoop(uint32_t strLen, std::vector<std::string> &result);
        void num2Str(uint32_t num, uint32_t strLen, std::string &current);

        void generateStrByItr(uint32_t strLen, std::vector<std::string> &result);
        void iter2Str(std::string &curr, uint32_t strLen,
                        std::vector<std::string> &result);
};
}

namespace method2 {
class LC0022_GenerateParentheses {
    public:
        std::vector<std::string> generateParenthesis(int n);
};
}

#endif // LC0022_GENERATE_PARENTHESES_H
 