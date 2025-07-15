/*
 * Time : 2025-07-15 09:29:10
 * URL  : https://leetcode.cn/problems/valid-word/submissions/644005855/?envType=daily-question&envId=2025-07-15
 */
#include "lc3xxx/lc31xx/lc313x/lc3136_valid_word.h"

#include <cstdint>
#include <string>

using namespace std;

bool LC3136_ValidWord::isValid(std::string word)
{
    if (word.size() < 3) {
        return false;
    }
    uint32_t vowelsCnt = 0;
    uint32_t consonantCnt = 0;
    for (const auto& c : word) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' ||
                c == 'O' || c == 'U') {
                vowelsCnt++;
            } else {
                consonantCnt++;
            }
        } else if (c < '0' || c > '9') {
            return false;
        }
    }
    return (vowelsCnt > 0 && consonantCnt > 0);
}
