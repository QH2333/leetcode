// 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int currNum = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            if (!count) // Initialize
            {
                currNum = *iter;
                nums[count] = currNum;
                count++;
                continue;
            }
            if (currNum != *iter)
            {
                currNum = *iter;
                nums[count] = currNum;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> vData({});
    cout << s.removeDuplicates(vData) << endl;
    return 0;
}