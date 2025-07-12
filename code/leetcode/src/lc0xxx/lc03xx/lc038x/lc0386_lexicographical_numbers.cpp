/*
 * Time : 2025-06-08 00:54:01
 * URL  :
 * https://leetcode.cn/problems/lexicographical-numbers/description/?envType=daily-questionURL_STRenvId=2025-06-08
 */
#include "lc0xxx/lc03xx/lc038x/lc0386_lexicographical_numbers.h"

#include <cstddef>
#include <cstdint>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace {
constexpr int32_t NINE = 9;
constexpr int32_t TEN = 10;
}  // namespace

vector<int32_t> LC0386_LexicographicalNumbers_Str2Num::lexicalOrder(int32_t n)
{
    set<string> strSet;
    for (int32_t i = 1; i <= n; i++) {
        strSet.insert(to_string(i));
    }

    vector<int32_t> ans;
    ans.reserve(static_cast<size_t>(n));
    for (const string &x : strSet) {
        ans.push_back(stoi(x));
    }

    return ans;
}

vector<int32_t> LC0386_LexicographicalNumbers_DFS::lexicalOrder(int32_t n)
{
    vector<int32_t> ans;
    ans.reserve(static_cast<size_t>(n));

    auto dfs = [&](auto &&dfs, int32_t base) -> bool {
        if (base > n) {
            return false;
        }

        if (base != 0) {
            ans.push_back(base);
        }

        for (int32_t i = (base == 0 ? 1 : 0); i <= NINE; ++i) {
            if (!dfs(dfs, base * TEN + i)) {
                break;
            }
        }
        return true;
    };

    dfs(dfs, 0);

    return ans;
}

NumIterator::NumIterator(const int limit) : limit(limit) {}

bool NumIterator::HasNext() const
{
    return num > 0;
}

int32_t NumIterator::Next()
{
    int32_t ret = num;

    if (num * TEN <= limit) {
        num *= TEN;
    } else {
        while (num % TEN == NINE || num + 1 > limit) {
            num /= TEN;
        }
        if (num != 0) {
            num++;
        }
    }

    return ret;
}

vector<int32_t> LC0386_LexicographicalNumbers_Iterator::lexicalOrder(int32_t n)
{
    NumIterator iter(n);

    vector<int32_t> ans;
    ans.reserve(static_cast<size_t>(n));

    while (iter.HasNext()) {
        ans.push_back(iter.Next());
    }

    return ans;
}
