/*
 * Time : 2025-05-24 00:13:40
 * URL  :
 * https://leetcode.cn/problems/find-words-containing-character/description/?envType=daily-questionURL_STRenvId=2025-05-24
 */
#ifndef LC2942_FIND_WORDS_CONTAINING_CHARACTER_H
#define LC2942_FIND_WORDS_CONTAINING_CHARACTER_H

#include <string>
#include <vector>

class LC2942_FindWordsContainingCharacter {
    public:
        LC2942_FindWordsContainingCharacter() = default;
        virtual ~LC2942_FindWordsContainingCharacter() = default;
        std::vector<int> findWordsContaining(std::vector<std::string>& words, char x);
};

#endif  // LC2942_FIND_WORDS_CONTAINING_CHARACTER_H
