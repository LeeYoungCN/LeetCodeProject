/*
 * Time : 2025-07-05 10:37:30
 * URL  :
 * https://leetcode.cn/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05
 */

#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc13xx/lc139x/lc1394_find_lucky_integer_in_an_array.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC1394 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1394_FindLuckyIntegerInAnArray*> m_testList;
    void RunTest(std::vector<int32_t>& arr, const int32_t& expect);
};

void TEST_LC1394::SetUp()
{
    m_testList.push_back(new LC1394_FindLuckyIntegerInAnArray());
}

void TEST_LC1394::TearDown()
{
    for (LC1394_FindLuckyIntegerInAnArray* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1394::RunTest(std::vector<int32_t>& arr, const int32_t& expect)
{
    for (LC1394_FindLuckyIntegerInAnArray* inst : m_testList) {
        int32_t result = inst->findLucky(arr);
        EXPECT_EQ(expect, result) << Vector2String(arr);
    }
}

TEST_F(TEST_LC1394, case1)
{
    std::vector<int32_t> arr = String2VecInt("[2,2,3,4]");
    const int32_t expect = 2;
    RunTest(arr, expect);
}

TEST_F(TEST_LC1394, case2)
{
    std::vector<int32_t> arr = String2VecInt("[1,2,2,3,3,3]");
    const int32_t expect = 3;
    RunTest(arr, expect);
}

TEST_F(TEST_LC1394, case3)
{
    std::vector<int32_t> arr = String2VecInt("[2,2,2,3,3]");
    const int32_t expect = -1;
    RunTest(arr, expect);
}

TEST_F(TEST_LC1394, case4)
{
    std::vector<int32_t> arr = String2VecInt("[5]");
    const int32_t expect = -1;
    RunTest(arr, expect);
}

TEST_F(TEST_LC1394, case5)
{
    std::vector<int32_t> arr = String2VecInt("[7,7,7,7,7,7,7]");
    const int32_t expect = 7;
    RunTest(arr, expect);
}
