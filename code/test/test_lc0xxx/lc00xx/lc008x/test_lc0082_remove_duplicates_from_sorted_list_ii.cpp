/*
 * Time : 2025-08-15 11:15:53
 * URL  : https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
 */

#include <cstdint>
#include <ostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc008x/lc0082_remove_duplicates_from_sorted_list_ii.h"
#include "leetcode_utils/leetcode_utils_list.hpp"

using namespace std;

class TEST_LC0082_Params {
public:
    TEST_LC0082_Params() = delete;

    TEST_LC0082_Params(std::string &&head, std::string &&expect) : head(CreateList(head)), expect(CreateList(expect))
    {
        refCnt = new std::atomic<int32_t>(1);
    };

    ~TEST_LC0082_Params() { freeMemberParams_(); };

    TEST_LC0082_Params(const TEST_LC0082_Params &other) { copyMemberParams_(other); }

    TEST_LC0082_Params &operator=(const TEST_LC0082_Params &other)
    {
        if (this == &other) {
            return *this;
        }

        freeMemberParams_();
        copyMemberParams_(other);

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC0082_Params &params)
    {
        os << "refCnt: " << params.refCnt->load() << std::endl;
        os << "head: ";
        if (params.head) {
            os << *params.head;
        } else {
            os << "{}";
        }
        return os;
    };

public:
    ListNode *head{nullptr};
    ListNode *expect{nullptr};

private:
    std::atomic<int32_t> *refCnt{nullptr};

private:
    void freeMemberParams_()
    {
        int32_t oldCnt = refCnt->fetch_sub(1, std::memory_order_relaxed);
        if (oldCnt == 1) {
            FreeList(head);
            FreeList(expect);
            delete refCnt;
        }
    }

    void copyMemberParams_(const TEST_LC0082_Params &other)
    {
        refCnt = other.refCnt;
        refCnt->fetch_add(1, std::memory_order_relaxed);
        head = other.head;
        expect = other.expect;
    }
};

class TEST_LC0082 : public ::testing::TestWithParam<TEST_LC0082_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0082_RemoveDuplicatesFromSortedListII *> m_testList;
};

void TEST_LC0082::SetUp()
{
    m_testList.push_back(new LC0082_RemoveDuplicatesFromSortedListII());
}

void TEST_LC0082::TearDown()
{
    for (LC0082_RemoveDuplicatesFromSortedListII *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC0082, case)
{
    const TEST_LC0082_Params &params = GetParam();
    ListNode *expect = params.expect;
    for (LC0082_RemoveDuplicatesFromSortedListII *inst : m_testList) {
        ListNode *result = inst->deleteDuplicates(params.head);
        if (expect != nullptr && result != nullptr) {
            EXPECT_EQ(*expect, *result);
        } else {
            EXPECT_EQ(expect, result);
        }
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC0082,
                         ::testing::Values(TEST_LC0082_Params("[1,2,3,3,4,4,5]", "[1,2,5]"),
                                           TEST_LC0082_Params("[1,1,1,2,3]", "[2,3]"),
                                           TEST_LC0082_Params("[1,1,1]", "[]"), TEST_LC0082_Params("[1]", "[1]"),
                                           TEST_LC0082_Params("[]", "[]"), TEST_LC0082_Params("[1,2,2]", "[1]")));
