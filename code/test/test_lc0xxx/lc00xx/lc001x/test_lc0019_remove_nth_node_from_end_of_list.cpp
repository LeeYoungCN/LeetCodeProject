/*
 * Time : 2025-08-15 19:22:46
 * URL  : https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc001x/lc0019_remove_nth_node_from_end_of_list.h"
#include "leetcode_utils/leetcode_utils_list.hpp"
#include "leetcode_utils/leetcode_utils_logging.hpp"

using namespace std;

class TEST_LC0019_Params {
public:
    TEST_LC0019_Params() = delete;
    TEST_LC0019_Params(std::string &&head, int32_t n, std::string &&expect)
        : head(CreateList(head)), n(n), expect(CreateList(expect))
    {
        refCnt = new std::atomic<int32_t>(1);
        DEBUG_LOG_DBG("refCnt: {}.", refCnt->load());
    };

    ~TEST_LC0019_Params() { freeMemberParams_(); };

    TEST_LC0019_Params(const TEST_LC0019_Params &other) { copyMemberParams_(other); }

    TEST_LC0019_Params &operator=(const TEST_LC0019_Params &other)
    {
        if (this == &other) {
            return *this;
        }
        freeMemberParams_();
        copyMemberParams_(other);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC0019_Params &params)
    {
        os << "refCnt: " << params.refCnt->load() << std::endl;
        os << "head: " << ToString(params.head) << ", n: " << params.n;
        return os;
    };

public:
    ListNode *head{};
    int32_t n{};
    ListNode *expect{};

private:
    std::atomic<int32_t> *refCnt{nullptr};

private:
    void freeMemberParams_()
    {
        int32_t oldCnt = refCnt->fetch_sub(1, std::memory_order_relaxed);
        DEBUG_LOG_DBG("refCnt: {}.", refCnt->load());
        if (oldCnt == 1) {
            /* Free */
            FreeList(head);
            FreeList(expect);
            delete refCnt;
            refCnt = nullptr;
        }
    }

    void copyMemberParams_(const TEST_LC0019_Params &other)
    {
        refCnt = other.refCnt;
        refCnt->fetch_add(1, std::memory_order_relaxed);
        DEBUG_LOG_DBG("refCnt: {}.", refCnt->load());
        head = other.head;
        expect = other.expect;
        n = other.n;
    }
};

class TEST_LC0019 : public ::testing::TestWithParam<TEST_LC0019_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0019_RemoveNthNodeFromEndOfList *> m_testList;
};

void TEST_LC0019::SetUp()
{
    m_testList.push_back(new LC0019_RemoveNthNodeFromEndOfList());
}

void TEST_LC0019::TearDown()
{
    for (LC0019_RemoveNthNodeFromEndOfList *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC0019, case)
{
    const TEST_LC0019_Params &params = GetParam();
    ListNode *expect = params.expect;
    for (LC0019_RemoveNthNodeFromEndOfList *inst : m_testList) {
        ListNode *result = inst->removeNthFromEnd(params.head, params.n);
        if (expect != nullptr && result != nullptr) {
            EXPECT_EQ(*expect, *result);
        } else {
            EXPECT_EQ(expect, result);
        }
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC0019,
                         ::testing::Values(TEST_LC0019_Params("[1,2,3,4,5]", 2, "[1,2,3,5]")
                                           //                TEST_LC0019_Params("[1]", 1, "[]"),
                                           //    TEST_LC0019_Params("[1,2]", 1, "[1]")
                                           ));
