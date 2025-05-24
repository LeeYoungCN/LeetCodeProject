/*
 * Time : 2025-05-19 21:27:40
 * URL  : https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 */
#ifndef LC0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define LC0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#include <cstdint>
#include <string>
#include <vector>

class LC0017_LetterCombinationsOfAPhoneNumber {
    public:
        std::vector<std::string> letterCombinations(std::string digits);

    private:
        void getResultByItr(uint32_t layer, std::string &curr, std::vector<std::string> &result);
        std::string m_digits;
};

#endif  // LC0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
