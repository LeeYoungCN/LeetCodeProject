/*
 * Time : 2025-08-15 15:21:49
 * URL  : https://leetcode.cn/problems/swap-nodes-in-pairs/
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc002x/lc0024_swap_nodes_in_pairs.h"
#include "leetcode_utils/leetcode_utils_list.hpp"

using namespace std;

class TEST_LC0024_Params {
public:
    TEST_LC0024_Params() = default;

    TEST_LC0024_Params(std::string &&head, std::string &&expect)
        : head(CreateList(head)), expect(CreateList(expect)) {};

    ~TEST_LC0024_Params() { freeMemberParams_(); };

    TEST_LC0024_Params(const TEST_LC0024_Params &other) { copyMemberParams_(other); }

    TEST_LC0024_Params &operator=(const TEST_LC0024_Params &other)
    {
        if (this == &other) {
            return *this;
        }
        freeMemberParams_();
        copyMemberParams_(other);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC0024_Params &params)
    {
        os << "refCnt: " << params.refCnt->load() << std::endl;
        os << ToString(params.head);
        return os;
    };

public:
    ListNode *head{nullptr};
    ListNode *expect{nullptr};

private:
    std::atomic<int32_t> *refCnt = new std::atomic<int32_t>(1);

private:
    void freeMemberParams_()
    {
        int32_t oldCnt = refCnt->fetch_sub(1, std::memory_order_relaxed);
        if (oldCnt == 1) {
            FreeList(expect);
            FreeList(head);
            delete refCnt;
            refCnt = nullptr;
        }
    }

    void copyMemberParams_(const TEST_LC0024_Params &other)
    {
        refCnt = other.refCnt;
        refCnt->fetch_add(1, std::memory_order_relaxed);
        expect = other.expect;
        head = other.head;
    }
};

class TEST_LC0024 : public ::testing::TestWithParam<TEST_LC0024_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0024_SwapNodesInPairs *> m_testList;
};

void TEST_LC0024::SetUp()
{
    m_testList.push_back(new LC0024_SwapNodesInPairs());
}

void TEST_LC0024::TearDown()
{
    for (LC0024_SwapNodesInPairs *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC0024, case)
{
    const TEST_LC0024_Params &params = GetParam();
    ListNode *expect = params.expect;
    for (LC0024_SwapNodesInPairs *inst : m_testList) {
        ListNode *result = inst->swapPairs(params.head);
        if (expect != nullptr && result != nullptr) {
            EXPECT_EQ(*expect, *result);
        } else {
            EXPECT_EQ(expect, result);
        }
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC0024,
                         ::testing::Values(TEST_LC0024_Params("[1,2,3,4]", "[2,1,4,3]"), TEST_LC0024_Params("[]", "[]"),
                                           TEST_LC0024_Params("[1]", "[1]"), TEST_LC0024_Params("[1,2,3]", "[2,1,3]")));
