/*
 * Time : 2025-05-19 16:35:29
 * URL  : https://leetcode.cn/problems/generate-parentheses/description/?envType=daily-questionURL_STRenvId=2025-05-18
 */

#include <cstdint>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include "lc0022_generate_parentheses.h"

using namespace std;
namespace method1 {
void LC0022_GenerateParentheses::num2Str(uint32_t num, uint32_t strLen, string &current)
{
    for (uint32_t i = 0; i < strLen; ++i) {
        if (num % 2 == 0) {
            current += '(';
        } else {
            current += ')';
        }
        num /= 2;
    }
}

bool LC0022_GenerateParentheses::isValidStr(const string &str)
{
    int32_t n = 0;
    for (const char c : str) {
        if (c == '(') {
            ++n;
        } else {
            --n;
        }
        if (n < 0) {
            return false;
        }
    }
    return (n == 0);
}

void LC0022_GenerateParentheses::generateStrByLoop(uint32_t strLen,
                                                   vector<string> &result)
{
    uint32_t total = pow(2, strLen);
    for (uint32_t i = 0; i < total; ++i) {
        string curr = "";
        curr.reserve(strLen);
        num2Str(i, strLen, curr);
        if (isValidStr(curr)) {
            result.push_back(curr);
        }
    }
}

vector<string> LC0022_GenerateParentheses::generateParenthesis(int n)
{
    uint32_t strLen = 2 * n;
    vector<string> result;

    generateStrByItr(strLen, result);
    return result;
}

void LC0022_GenerateParentheses::generateStrByItr(uint32_t strLen, vector<string> &result)
{
    string curr = "";
    curr.reserve(strLen);
    iter2Str(curr, strLen, result);
}

void LC0022_GenerateParentheses::iter2Str(string &curr, uint32_t strLen,
                                          vector<string> &result)
{
    if (curr.size() >= strLen) {
        if (isValidStr(curr)) {
            result.push_back(curr);
        }
        return;
    }
    curr.push_back('(');
    iter2Str(curr, strLen, result);
    curr.pop_back();
    curr.push_back(')');
    iter2Str(curr, strLen, result);
    curr.pop_back();
}
}


namespace method2 {
void generateStrByItr(string &curr, vector<string> &result, uint32_t leftNum, uint32_t rightNum, uint32_t maxCnt)
{
    if (curr.size() == maxCnt * 2) {
        result.push_back(curr);
        return;
    }
    if (leftNum < maxCnt) {
        curr.push_back('(');
        generateStrByItr(curr, result, leftNum + 1, rightNum, maxCnt);
        curr.pop_back();
    }

    if (leftNum > rightNum) {
        curr.push_back(')');
        generateStrByItr(curr, result, leftNum, rightNum + 1, maxCnt);
        curr.pop_back();
    }
}

vector<string> LC0022_GenerateParentheses::generateParenthesis(int n)
{
    string curr = "";
    curr.reserve(2 * n);
    vector<string> result;
    generateStrByItr(curr, result, 0, 0, n);
    return result;
}

}