// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 你可以假设数组中无重复元素。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int count = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            if (*iter < target)
            {
                count++;
                continue;
            }
            else
            {
                return count;
            }
        }
        return count;            
    }
};

int main()
{
    vector<int> vData({1,2,3});
    Solution s;
    cout << s.searchInsert(vData, 4) << endl;
    return 0;
}