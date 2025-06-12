/*
 * Time : 2025-05-27 18:47:36
 * URL  : https://leetcode.cn/problems/partition-equal-subset-sum/
 */
#ifndef LC0426_PARTITION_EQUAL_SUBSET_SUM_H
#define LC0426_PARTITION_EQUAL_SUBSET_SUM_H

#include <vector>

class LC0426_PartitionEqualSubsetSum {
public:
    LC0426_PartitionEqualSubsetSum() = default;
    virtual ~LC0426_PartitionEqualSubsetSum() = default;
    virtual bool canPartition(std::vector<int>& nums) = 0;
};

class LC0426_PartitionEqualSubsetSum_DP1 : public LC0426_PartitionEqualSubsetSum {
public:
    LC0426_PartitionEqualSubsetSum_DP1() = default;
    ~LC0426_PartitionEqualSubsetSum_DP1() override = default;
    bool canPartition(std::vector<int>& nums) final;
};

class LC0426_PartitionEqualSubsetSum_DP2 : public LC0426_PartitionEqualSubsetSum {
public:
    LC0426_PartitionEqualSubsetSum_DP2() = default;
    ~LC0426_PartitionEqualSubsetSum_DP2() override = default;
    bool canPartition(std::vector<int>& nums) final;
};

#endif  // LC0426_PARTITION_EQUAL_SUBSET_SUM_H
