/*
 * Time : 2025-07-19 09:28:02
 * URL  :
 * https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2025-07-19
 */
#include "lc1xxx/lc12xx/lc123x/lc1233_remove_sub_folders_from_the_filesystem.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> LC1233_RemoveSubFoldersFromTheFilesystem::removeSubfolders(std::vector<std::string>& folder)
{
    sort(folder.begin(), folder.end());

    std::vector<std::string> ans;
    uint32_t idx = 0;

    for (const auto& f : folder) {
        auto pos = f.find_last_of('/');
        if (pos == 0 || pos == f.size() - 1) {
            ans.emplace_back(f);
            continue;
        }
        for (; idx < ans.size(); idx++) {
            std::size_t l = ans[idx].size();
            if ((ans[idx] == f.substr(0, l)) && (f[l] == '/')) {
                break;
            }
        }
        if (idx == ans.size()) {
            ans.emplace_back(f);
        }
    }

    return ans;
}
