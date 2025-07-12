// https://leetcode.cn/problems/type-of-triangle/?envType=daily-questionURL_STRenvId=2025-05-19
#include "lc3xxx/lc30xx/lc302x/lc3024_type_of_triangle.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    uint32_t cmpLine1;
    uint32_t cmpLine2;
    uint32_t addLine;
} TriLineArr;

string LC3024_TypeOfTriangle::triangleType(vector<int>& nums)
{
    const vector<TriLineArr> checkList = {{0, 1, 2}, {0, 2, 1}, {1, 2, 0}};
    bool isValid = true;
    uint32_t equalLineNum = 0;
    for (const TriLineArr lineArr : checkList) {
        if (nums[lineArr.cmpLine1] == nums[lineArr.cmpLine2]) {
            equalLineNum++;
        }
        if (nums[lineArr.cmpLine1] + nums[lineArr.cmpLine2] <= nums[lineArr.addLine]) {
            isValid = false;
            break;
        }
    }
    if (isValid) {
        const string ans[] = {"scalene", "isosceles", "isosceles", "equilateral"};
        return ans[equalLineNum];
    } else {
        return "none";
    }
}
