/*
 * Time : 2025-07-16 09:26:47
 * URL  :
 * https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-i/description/?envType=daily-question&envId=2025-07-16
 */
#include "lc3xxx/lc32xx/lc320x/lc3201_find_the_maximum_length_of_valid_subsequence_i.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC3201_FindTheMaximumLengthOfValidSubsequenceI::maximumLength(std::vector<int32_t>& nums)
{
    std::vector<std::vector<int32_t>> statusList{{0, 0}, {1, 1}, {1, 0}, {0, 1}};
    uint32_t ans = 0;
    for (const auto& status : statusList) {
        uint32_t cnt = 0;
        for (const auto& num : nums) {
            if (num % 2 == status[cnt % 2]) {
                cnt++;
            }
        }
        ans = max(cnt, ans);
    }
    return static_cast<int32_t>(ans);
}
