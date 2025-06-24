/*
 * Time : 2025-06-08 00:54:01
 * URL  :
 * https://leetcode.cn/problems/lexicographical-numbers/description/?envType=daily-questionURL_STRenvId=2025-06-08
 */
#ifndef LC0386_LEXICOGRAPHICAL_NUMBERS_H
#define LC0386_LEXICOGRAPHICAL_NUMBERS_H

#include <vector>

class LC0386_LexicographicalNumbers {
public:
    LC0386_LexicographicalNumbers() = default;
    virtual ~LC0386_LexicographicalNumbers() = default;
    virtual std::vector<int> lexicalOrder(int n) = 0;
};

class LC0386_LexicographicalNumbers_Str2Num : public LC0386_LexicographicalNumbers {
public:
    LC0386_LexicographicalNumbers_Str2Num() = default;
    ~LC0386_LexicographicalNumbers_Str2Num() override = default;
    std::vector<int> lexicalOrder(int n) final;
};

class LC0386_LexicographicalNumbers_DFS : public LC0386_LexicographicalNumbers {
public:
    LC0386_LexicographicalNumbers_DFS() = default;
    ~LC0386_LexicographicalNumbers_DFS() override = default;
    std::vector<int> lexicalOrder(int n) final;
};

class NumIterator {
public:
    NumIterator() = default;
    explicit NumIterator(int limit);
    ~NumIterator() = default;
    [[nodiscard]] bool HasNext() const;
    int Next();

private:
    int num = 1;
    int limit{};
};

class LC0386_LexicographicalNumbers_Iterator : public LC0386_LexicographicalNumbers {
public:
    LC0386_LexicographicalNumbers_Iterator() = default;
    ~LC0386_LexicographicalNumbers_Iterator() override = default;
    std::vector<int> lexicalOrder(int n) final;
};

#endif  // LC0386_LEXICOGRAPHICAL_NUMBERS_H
