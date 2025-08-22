/*
 * Time : 2025-08-14 18:19:47
 * URL  : https://leetcode.cn/problems/add-two-numbers/description/
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc000x/lc0002_add_two_numbers.h"
#include "leetcode_utils/leetcode_utils_list.hpp"

using namespace std;

class TEST_LC0002_Params {
public:
    TEST_LC0002_Params() = default;
    ~TEST_LC0002_Params()
    {
        int oldCnt = refCnt->fetch_sub(1, std::memory_order_acq_rel);
        if (oldCnt == 1) {
            FreeList(l1);
            l1 = nullptr;
            FreeList(l2);
            l2 = nullptr;
            FreeList(expect);
            expect = nullptr;
            delete refCnt;
            refCnt = nullptr;
        }
    };

    TEST_LC0002_Params(const std::string &l1, const std::string &l2, const std::string &expect)
        : l1(CreateList(l1)), l2(CreateList(l2)), expect(CreateList(expect)) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC0002_Params &params)
    {
        os << std::endl << "refCnt: " << params.refCnt->load() << std::endl;
        os << "l1: " << *params.l1 << ", l2: " << *params.l2;
        return os;
    };

    TEST_LC0002_Params(const TEST_LC0002_Params &other)
    {
        refCnt = other.refCnt;
        refCnt->fetch_add(1, std::memory_order_relaxed);
        l1 = other.l1;
        l2 = other.l2;
        expect = other.expect;
    }

    TEST_LC0002_Params &operator=(const TEST_LC0002_Params &other)
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

class TEST_LC0002 : public ::testing::TestWithParam<TEST_LC0002_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0002_AddTwoNumbers *> m_testList;
};

void TEST_LC0002::SetUp()
{
    m_testList.push_back(new LC0002_AddTwoNumbers());
}

void TEST_LC0002::TearDown()
{
    for (LC0002_AddTwoNumbers *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC0002, case)
{
    const auto &params = GetParam();
    TEST_LC0002_Params x{};
    ListNode *expect = params.expect;
    for (LC0002_AddTwoNumbers *inst : m_testList) {
        ListNode *result = inst->addTwoNumbers(params.l1, params.l2);
        EXPECT_EQ(*expect, *result);
        FreeList(result);
    }
}

INSTANTIATE_TEST_SUITE_P(, TEST_LC0002,
                         ::testing::Values(TEST_LC0002_Params("[2,4,3]", "[5,6,4]", "[7,0,8]"),
                                           TEST_LC0002_Params("[0]", "[0]", "[0]"),
                                           TEST_LC0002_Params("[9,9,9,9,9,9,9]", "[9,9,9,9]", "[8,9,9,9,0,0,0,1]")));
