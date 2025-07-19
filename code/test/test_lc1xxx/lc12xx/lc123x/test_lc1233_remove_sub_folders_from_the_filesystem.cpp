/*
 * Time : 2025-07-19 09:28:02
 * URL  :
 * https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2025-07-19
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc12xx/lc123x/lc1233_remove_sub_folders_from_the_filesystem.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC1233_Params {
public:
    TEST_LC1233_Params() = default;
    ~TEST_LC1233_Params() = default;
    TEST_LC1233_Params(const std::vector<std::string> &folder, const std::vector<std::string> &expect)
        : folder(folder), expect(expect) {};

    friend std::ostream &operator<<(std::ostream &os, const TEST_LC1233_Params &params)
    {
        os << Vector2String(params.folder);
        return os;
    };

public:
    std::vector<std::string> folder;
    std::vector<std::string> expect;
};

class TEST_LC1233 : public ::testing::TestWithParam<TEST_LC1233_Params> {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1233_RemoveSubFoldersFromTheFilesystem *> m_testList;
};

void TEST_LC1233::SetUp()
{
    m_testList.push_back(new LC1233_RemoveSubFoldersFromTheFilesystem());
}

void TEST_LC1233::TearDown()
{
    for (LC1233_RemoveSubFoldersFromTheFilesystem *inst : m_testList) {
        delete inst;
    }
}

TEST_P(TEST_LC1233, case)
{
    TEST_LC1233_Params params = GetParam();
    std::vector<std::string> expect = params.expect;
    for (LC1233_RemoveSubFoldersFromTheFilesystem *inst : m_testList) {
        std::vector<std::string> result = inst->removeSubfolders(params.folder);
        sort(expect.begin(), expect.end());
        sort(result.begin(), result.end());
        EXPECT_EQ(expect, result);
    }
}

INSTANTIATE_TEST_SUITE_P(
    , TEST_LC1233,
    ::testing::Values(TEST_LC1233_Params({"/a", "/a/b/c", "/a/b/d"}, {"/a"}),
                      TEST_LC1233_Params({"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"}, {"/a", "/c/d", "/c/f"}),
                      TEST_LC1233_Params({"/a/b/c", "/a/b/ca", "/a/b/d"}, {"/a/b/c", "/a/b/ca", "/a/b/d"})));
