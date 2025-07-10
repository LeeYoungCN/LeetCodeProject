/*
 * Time : 2025-05-24 00:13:40
 * URL  :
 * https://leetcode.cn/problems/find-words-containing-character/description/?envType=daily-questionURL_STRenvId=2025-05-24
 */
#include "lc29xx/lc2942_find_words_containing_character.h"

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

std::vector<int> LC2942_FindWordsContainingCharacter::findWordsContaining(std::vector<std::string>& words, char x)
{
    auto isInStr = [](const string& word, char x) -> bool {
        return std::any_of(word.begin(), word.end(), [x](const char& c) { return c == x; });
    };

    vector<int32_t> ret;
    for (uint32_t i = 0; i < words.size(); i++) {
        if (isInStr(words.at(i), x)) {
            ret.push_back(static_cast<int32_t>(i));
        }
    }
    return ret;
}
