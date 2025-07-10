/*
 * Time : 2025-06-03 00:02:53
 * URL  :
 * https://leetcode.cn/problems/maximum-candies-you-can-get-from-boxes/description/?envType=daily-questionURL_STRenvId=2025-06-03
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc12xx/lc1298_maximum_candies_you_can_get_from_boxes.h"

using namespace std;

class TEST_LC1298 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1298_MaximumCandiesYouCanGetFromBoxes*> m_testList;
    void RunTest(std::vector<int>& status, std::vector<int>& candies, std::vector<std::vector<int>>& keys,
                 std::vector<std::vector<int>>& containedBoxes, std::vector<int>& initialBoxes, int expect);
};

void TEST_LC1298::SetUp()
{
    m_testList.push_back(new LC1298_MaximumCandiesYouCanGetFromBoxes());
}

void TEST_LC1298::TearDown()
{
    for (LC1298_MaximumCandiesYouCanGetFromBoxes* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1298::RunTest(std::vector<int>& status, std::vector<int>& candies, std::vector<std::vector<int>>& keys,
                          std::vector<std::vector<int>>& containedBoxes, std::vector<int>& initialBoxes, int expect)
{
    for (LC1298_MaximumCandiesYouCanGetFromBoxes* inst : m_testList) {
        EXPECT_EQ(expect, inst->maxCandies(status, candies, keys, containedBoxes, initialBoxes));
    }
}

TEST_F(TEST_LC1298, case1)
{
    std::vector<int> status = {1, 0, 1, 0};
    std::vector<int> candies = {7, 5, 4, 100};
    std::vector<std::vector<int>> keys = {{}, {}, {1}, {}};
    std::vector<std::vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
    std::vector<int> initialBoxes = {0};
    int expect = 16;
    RunTest(status, candies, keys, containedBoxes, initialBoxes, expect);
}

TEST_F(TEST_LC1298, case2)
{
    std::vector<int> status = {1, 0, 0, 0, 0, 0};
    std::vector<int> candies = {1, 1, 1, 1, 1, 1};
    std::vector<std::vector<int>> keys = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    std::vector<std::vector<int>> containedBoxes = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    std::vector<int> initialBoxes = {0};
    int expect = 6;
    RunTest(status, candies, keys, containedBoxes, initialBoxes, expect);
}

TEST_F(TEST_LC1298, case3)
{
    std::vector<int> status = {1, 1, 1};
    std::vector<int> candies = {100, 1, 100};
    std::vector<std::vector<int>> keys = {{}, {0, 2}, {}};
    std::vector<std::vector<int>> containedBoxes = {{}, {}, {}};
    std::vector<int> initialBoxes = {1};
    int expect = 1;
    RunTest(status, candies, keys, containedBoxes, initialBoxes, expect);
}

TEST_F(TEST_LC1298, case4)
{
    std::vector<int> status = {1};
    std::vector<int> candies = {100};
    std::vector<std::vector<int>> keys = {{}};
    std::vector<std::vector<int>> containedBoxes = {{}};
    std::vector<int> initialBoxes = {};
    int expect = 0;
    RunTest(status, candies, keys, containedBoxes, initialBoxes, expect);
}
TEST_F(TEST_LC1298, case5)
{
    std::vector<int> status = {1, 1, 1};
    std::vector<int> candies = {2, 3, 2};
    std::vector<std::vector<int>> keys = {{}, {}, {}};
    std::vector<std::vector<int>> containedBoxes = {{}, {}, {}};
    std::vector<int> initialBoxes = {2, 1, 0};
    int expect = 7;
    RunTest(status, candies, keys, containedBoxes, initialBoxes, expect);
}
