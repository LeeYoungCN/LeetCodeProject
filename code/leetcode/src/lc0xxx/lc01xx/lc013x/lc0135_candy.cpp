/*
 * Time : 2025-06-02 00:20:13
 * URL  : https://leetcode.cn/problems/candy/description/?envType=daily-questionURL_STRenvId=2025-06-02
 */
#include "lc0xxx/lc01xx/lc013x/lc0135_candy.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

int LC0135_Candy_Stack::candy(std::vector<int>& ratings)
{
    const auto length = static_cast<uint32_t>(ratings.size());
    vector<uint32_t> idxStack;
    idxStack.reserve(length);

    vector<int32_t> childCandy(length, 0);
    childCandy[0] = 1;

    function<void(void)> processStack = [&]() -> void {
        int32_t n = 1;
        while (!idxStack.empty()) {
            uint32_t idx = idxStack.back();
            idxStack.pop_back();
            n = max(n, childCandy[idx]);

            childCandy[idx] = n++;
        }
    };

    for (uint32_t i = 1; i < length; i++) {
        int32_t currRating = ratings[i];
        int32_t preRating = ratings[i - 1];

        if (idxStack.empty()) {
            if (currRating == preRating) {
                childCandy[i] = 1;
            } else if (currRating > preRating) {
                childCandy[i] = childCandy[i - 1] + 1;
            } else {
                idxStack.push_back(i - 1);
                idxStack.push_back(i);
            }
        } else {
            int32_t stackRating = ratings[idxStack.back()];
            if (stackRating > currRating) {
                idxStack.push_back(i);
            } else {
                processStack();
                childCandy[i] = stackRating == currRating ? 1 : 2;
            }
        }
    }
    processStack();
    return accumulate(childCandy.begin(), childCandy.end(), 0);
}

int LC0135_Candy_TwoTraverse::candy(std::vector<int>& ratings)
{
    const auto length = static_cast<uint32_t>(ratings.size());

    vector<int32_t> leftCandy(length, 0);

    for (uint32_t i = 0; i < length; i++) {
        if (i > 0 && ratings[i] > ratings[i - 1]) {
            leftCandy[i] = leftCandy[i - 1] + 1;
        } else {
            leftCandy[i] = 1;
        }
    }

    int32_t ans = 0;
    int32_t right = 1;
    for (uint32_t j = 0; j < length; j++) {
        uint32_t i = length - j - 1;
        if (i < length - 1 && ratings[i] > ratings[i + 1]) {
            right++;
        } else {
            right = 1;
        }
        ans += max(right, leftCandy[i]);
    }
    return ans;
}

int LC0135_Candy_OneTraverse::candy(std::vector<int>& ratings)
{
    const auto length = static_cast<uint32_t>(ratings.size());

    int32_t ans = 1;
    int32_t pre = 1;
    int32_t inc = pre;
    int32_t dec = 0;

    for (uint32_t i = 1; i < length; i++) {
        if (ratings[i] >= ratings[i - 1]) {
            dec = 0;
            pre = (ratings[i] == ratings[i - 1] ? 1 : pre + 1);
            ans += pre;
            inc = pre;
        } else {
            dec++;
            if (dec == inc) {
                dec++;
            }
            ans += dec;
            pre = 1;
        }
    }

    return ans;
}
