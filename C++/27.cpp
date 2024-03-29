// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            if (*iter != val)
            {
                nums[count++] = *iter;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> vData({1,2,3,2,1,4,5,6});
    Solution s;
    cout << s.removeElement(vData, 2) << endl;
    return 0;
}