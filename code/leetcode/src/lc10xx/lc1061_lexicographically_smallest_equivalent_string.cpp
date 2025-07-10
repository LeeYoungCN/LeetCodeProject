/*
 * Time : 2025-06-05 19:17:03
 * URL  :
 * https://leetcode.cn/problems/lexicographically-smallest-equivalent-string/?envType=daily-questionURL_STRenvId=2025-06-05
 */
#include "lc10xx/lc1061_lexicographically_smallest_equivalent_string.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

UnionFind::UnionFind(uint32_t size)
{
    pa.resize(size);
    for (uint32_t i = 0; i < size; i++) {
        pa[i] = i;
    }
}

uint32_t UnionFind::Find(uint32_t x)
{
    while (pa[x] != x) {
        x = pa[x];
    }
    return x;
}

void UnionFind::Union(uint32_t x, uint32_t y)
{
    const uint32_t xRoot = Find(x);
    const uint32_t yRoot = Find(y);

    if (xRoot == yRoot) {
        return;
    }

    if (xRoot < yRoot) {
        pa[yRoot] = xRoot;
    } else {
        pa[xRoot] = yRoot;
    }
}

#define C2N(chr) uint32_t((chr) - 'a')
#define N2C(num) char((num) + 'a')

string LC1061_LexicographicallySmallestEquivalentString::smallestEquivalentString(string s1, string s2, string baseStr)
{
    constexpr uint32_t CHAR_NUM = 26;
    UnionFind uf(CHAR_NUM);

    const auto length = static_cast<uint32_t>(s1.size());
    for (uint32_t i = 0; i < length; i++) {
        uf.Union(C2N(s1[i]), C2N(s2[i]));
    }

    for (char &c : baseStr) {
        c = N2C(uf.Find(C2N(c)));
    }

    return baseStr;
}
