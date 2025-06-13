/*
 * Time : 2025-06-14 02:00:32
 * URL  : https://leetcode.cn/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-questionURL_STRenvId=2025-06-14
 */
#ifndef LC2566_MAXIMUM_DIFFERENCE_BY_REMAPPING_A_DIGIT_H
#define LC2566_MAXIMUM_DIFFERENCE_BY_REMAPPING_A_DIGIT_H

class LC2566_MaximumDifferenceByRemappingADigit {
public:
    LC2566_MaximumDifferenceByRemappingADigit() = default;
    virtual ~LC2566_MaximumDifferenceByRemappingADigit() = default;
    virtual int minMaxDifference(int num) = 0;
};

class LC2566_MaximumDifferenceByRemappingADigit_Math : public LC2566_MaximumDifferenceByRemappingADigit {
public:
    LC2566_MaximumDifferenceByRemappingADigit_Math() = default;
    ~LC2566_MaximumDifferenceByRemappingADigit_Math() override = default;
    int minMaxDifference(int num) final;
};

class LC2566_MaximumDifferenceByRemappingADigit_String : public LC2566_MaximumDifferenceByRemappingADigit {
public:
    LC2566_MaximumDifferenceByRemappingADigit_String() = default;
    ~LC2566_MaximumDifferenceByRemappingADigit_String() override = default;
    int minMaxDifference(int num) final;
};

#endif  // LC2566_MAXIMUM_DIFFERENCE_BY_REMAPPING_A_DIGIT_H
