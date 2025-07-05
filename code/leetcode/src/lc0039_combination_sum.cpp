/*
 * Time : 2025-06-29 18:45:48
 * URL  : https://leetcode.cn/problems/combination-sum/
 */
#include "lc0039_combination_sum.h"

#include <algorithm>
#include <cstdint>
#include <stack>
#include <vector>

using namespace std;

void LC0039_CombinationSum_DFS::dfs(const std::vector<int32_t>& candidates, vector<vector<int32_t>>& ans,
                                    vector<int32_t>& currVec, int32_t target, uint32_t startIdx)
{
    if (target < candidates[startIdx]) {
        return;
    }
    currVec.emplace_back(candidates[startIdx]);
    int32_t newTarget = target - candidates[startIdx];
    if (newTarget == 0) {
        ans.emplace_back(currVec);
    } else {
        for (uint32_t nextIdx = startIdx; nextIdx < candidates.size(); nextIdx++) {
            dfs(candidates, ans, currVec, newTarget, nextIdx);
        }
    }
    currVec.pop_back();
}

std::vector<std::vector<int32_t>> LC0039_CombinationSum_DFS::combinationSum(std::vector<int32_t>& candidates,
                                                                            int32_t target)
{
    sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int32_t>> ans;
    vector<int32_t> currVec;
    for (uint32_t i = 0; i < static_cast<uint32_t>(candidates.size()); i++) {
        dfs(candidates, ans, currVec, target, i);
    }

    return ans;
}

enum STATUS { START = 0, LOOP };

struct StackData {
    uint32_t currIdx;
    uint32_t nextIdx;
    int32_t currTarget;
    STATUS status;
};

std::vector<std::vector<int32_t>> LC0039_CombinationSum_Stack::combinationSum(std::vector<int32_t>& candidates,
                                                                              int32_t target)
{
    sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int32_t>> ans;
    vector<int32_t> currVec;
    stack<StackData> callStack;

    for (uint32_t i = 0; i < candidates.size(); ++i) {
        StackData testData = {.currIdx = i, .nextIdx = i, .currTarget = target, .status = START};
        callStack.emplace(testData);
    }

    while (!callStack.empty()) {
        StackData data = callStack.top();
        callStack.pop();
        switch (data.status) {
            case START:
                if (data.currTarget < candidates[data.currIdx]) {
                    break;
                }
                currVec.emplace_back(candidates[data.currIdx]);
                if (data.currTarget - candidates[data.currIdx] == 0) {
                    ans.emplace_back(currVec);
                    currVec.pop_back();
                    break;
                } else {
                    data.status = LOOP;
                }
            case LOOP:
                if (data.nextIdx == candidates.size()) {
                    currVec.pop_back();
                } else {
                    StackData nextData = {.currIdx = data.nextIdx,
                                          .nextIdx = data.nextIdx,
                                          .currTarget = data.currTarget - candidates[data.currIdx],
                                          .status = START};
                    data.nextIdx += 1;
                    callStack.emplace(data);
                    callStack.emplace(nextData);
                }
                break;
        };
    }

    return ans;
}
