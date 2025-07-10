/*
 * Time : 2025-06-02 15:42:25
 * URL  : https://leetcode.cn/problems/boats-to-save-people/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc08xx/lc0881_boats_to_save_people.h"

using namespace std;

class TEST_LC0881 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0881_BoatsToSavePeople *> m_testList;
    void RunTest(std::vector<int> &people, int limit, int expect);
};

void TEST_LC0881::SetUp()
{
    m_testList.push_back(new LC0881_BoatsToSavePeople());
}

void TEST_LC0881::TearDown()
{
    for (LC0881_BoatsToSavePeople *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0881::RunTest(std::vector<int> &people, int limit, int expect)
{
    for (LC0881_BoatsToSavePeople *inst : m_testList) {
        EXPECT_EQ(expect, inst->numRescueBoats(people, limit));
    }
}

TEST_F(TEST_LC0881, case1)
{
    std::vector<int> people = {1, 2};
    int limit = 3;
    int expect = 1;
    RunTest(people, limit, expect);
}

TEST_F(TEST_LC0881, case2)
{
    std::vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    int expect = 3;
    RunTest(people, limit, expect);
}

TEST_F(TEST_LC0881, case3)
{
    std::vector<int> people = {3, 5, 3, 4};
    int limit = 5;
    int expect = 4;
    RunTest(people, limit, expect);
}

TEST_F(TEST_LC0881, case4)
{
    std::vector<int> people = {3, 3, 3, 3, 3};
    int limit = 5;
    int expect = 5;
    RunTest(people, limit, expect);
}
