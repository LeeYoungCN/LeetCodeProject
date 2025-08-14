/*
 * Time : 2025-08-14 12:14:22
 * URL  : https://leetcode.cn/problems/add-two-numbers-ii/description/
 */

#include <atomic>
#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc04xx/lc044x/lc0445_add_two_numbers_ii.h"
#include "leetcode_utils_list.hpp"

using namespace std;

class TEST_LC0445_Params {
public:
    TEST_LC0445_Params() = default;
    ~TEST_LC0445_Params()
    {
        int oldCnt = refCnt->fetch_sub(1, std::memory_order_acq_rel);
        if (oldCnt == 1) {
            FreeList(l1);
            l1 = nullptr;
            FreeList(l2);
            l2 = nullptr;
            FreeList(expect);
            expect = nullptr;
        }
    };

    TEST_LC0445_Params(const std::string &l1, const std::string &l2, const std::string &expect)
        : l1(CreateList(l1)), l2(CreateList(l2)), expect(CreateList(expect)) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC0445_Params &params)
    {
        os << std::endl << "refCnt: " << params.refCnt->load() << std::endl;
        os << "l1: " << *params.l1 << ", l2: " << *params.l2;
        return os;
    };

    TEST_LC0445_Params(const TEST_LC0445_Params &other)
    {
        l1 = other.l1;
        l2 = other.l2;
        expect = other.expect;
        refCnt = other.refCnt;
        refCnt->fetch_add(1, std::memory_order_relaxed);
    }

    TEST_LC0445_Params &operator=(const TEST_LC0445_Params &other)
    {
        if (this == &other) {
            return *this;
        }
        int32_t oldCnt = refCnt->fetch_sub(1, std::memory_order_relaxed);
        if (oldCnt == 1) {
            FreeList(l1);
            l1 = nullptr;
            FreeList(l2);
            l2 = nullptr;
            FreeList(expect);
            expect = nullptr;
        }
        l1 = other.l1;
        l2 = other.l2;
        expect = other.expect;
        refCnt = other.refCnt;
        refCnt->fetch_add(1, std::memory_order_relaxed);
        return *this;
    }

public:
    ListNode *l1{nullptr};
    ListNode *l2{nullptr};
    ListNode *expect{nullptr};

protected:
    std::atomic<int32_t> *refCnt = new std::atomic<int32_t>(1);
};

class TEST_LC0445 : public ::testing::TestWithParam<TEST_LC0445_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0445_AddTwoNumbersII *> m_testList;
};

void TEST_LC0445::SetUp()
{
    m_testList.push_back(new LC0445_AddTwoNumbersII());
}

void TEST_LC0445::TearDown()
{
    for (LC0445_AddTwoNumbersII *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC0445, case)
{
    const auto &params = GetParam();
    ListNode *expect = params.expect;
    for (LC0445_AddTwoNumbersII *inst : m_testList) {
        ListNode *result = inst->addTwoNumbers(params.l1, params.l2);
        EXPECT_EQ((*expect), (*result)) << *result;
        FreeList(result);
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC0445,
                         ::testing::Values(TEST_LC0445_Params("[7,2,4,3]", "[5,6,4]", "[7,8,0,7]"),
                                           TEST_LC0445_Params("[2,4,3]", "[5,6,4]", "[8,0,7]"),
                                           TEST_LC0445_Params("[0]", "[0]", "[0]")));
