/*
 * Time : 2025-06-21 18:03:05
 * URL  : https://leetcode.cn/problems/delete-operation-for-two-strings/
 */
#ifndef LC0583_DELETE_OPERATION_FOR_TWO_STRINGS_H
#define LC0583_DELETE_OPERATION_FOR_TWO_STRINGS_H

#include <string>

class LC0583_DeleteOperationForTwoStrings {
public:
    LC0583_DeleteOperationForTwoStrings() = default;
    virtual ~LC0583_DeleteOperationForTwoStrings() = default;
    virtual int minDistance(std::string word1, std::string word2) = 0;
};

class LC0583_DeleteOperationForTwoStrings_MinDelete : public LC0583_DeleteOperationForTwoStrings {
public:
    LC0583_DeleteOperationForTwoStrings_MinDelete() = default;
    ~LC0583_DeleteOperationForTwoStrings_MinDelete() override = default;
    int minDistance(std::string word1, std::string word2) final;
};

class LC0583_DeleteOperationForTwoStrings_MaxCommon : public LC0583_DeleteOperationForTwoStrings {
public:
    LC0583_DeleteOperationForTwoStrings_MaxCommon() = default;
    ~LC0583_DeleteOperationForTwoStrings_MaxCommon() override = default;
    int minDistance(std::string word1, std::string word2) final;
};

#endif  // LC0583_DELETE_OPERATION_FOR_TWO_STRINGS_H
