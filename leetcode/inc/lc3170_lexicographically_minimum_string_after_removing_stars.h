/*
 * Time : 2025-06-07 00:42:01
 * URL  :
 * https://leetcode.cn/problems/lexicographically-minimum-string-after-removing-stars/description/?envType=daily-questionURL_STRenvId=2025-06-07
 */
#ifndef LC3170_LEXICOGRAPHICALLY_MINIMUM_STRING_AFTER_REMOVING_STARS_H
#define LC3170_LEXICOGRAPHICALLY_MINIMUM_STRING_AFTER_REMOVING_STARS_H

#include <string>

class LC3170_LexicographicallyMinimumStringAfterRemovingStars {
public:
    LC3170_LexicographicallyMinimumStringAfterRemovingStars() = default;
    virtual ~LC3170_LexicographicallyMinimumStringAfterRemovingStars() = default;
    virtual std::string clearStars(std::string s) = 0;
};

class LC3170_LexicographicallyMinimumStringAfterRemovingStars_Heap
    : public LC3170_LexicographicallyMinimumStringAfterRemovingStars {
public:
    LC3170_LexicographicallyMinimumStringAfterRemovingStars_Heap() = default;
    ~LC3170_LexicographicallyMinimumStringAfterRemovingStars_Heap() override = default;
    std::string clearStars(std::string s) override;
};

#endif  // LC3170_LEXICOGRAPHICALLY_MINIMUM_STRING_AFTER_REMOVING_STARS_H
