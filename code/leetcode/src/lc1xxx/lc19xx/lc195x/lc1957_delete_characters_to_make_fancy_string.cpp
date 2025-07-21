/*
 * Time : 2025-07-21 08:51:35
 * URL  :
 * https://leetcode.cn/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2025-07-21
 */
#include "lc1xxx/lc19xx/lc195x/lc1957_delete_characters_to_make_fancy_string.h"

#include <cstdint>
#include <string>

using namespace std;

std::string LC1957_DeleteCharactersToMakeFancyString::makeFancyString(std::string s)
{
    std::string ans;
    ans.reserve(s.size());
    char preChr = '\0';
    uint32_t preCnt = 0;
    for (const auto c : s) {
        if (c == preChr) {
            if (preCnt >= 2) {
                continue;
            } else {
                preCnt++;
                ans.push_back(c);
            }
        } else {
            ans.push_back(c);
            preCnt = 1;
            preChr = c;
        }
    }
    return ans;
}
