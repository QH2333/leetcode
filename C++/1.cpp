#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++)
        {
            numMap.insert(pair<int, int>(nums[i], i));
        }

        map<int, int>::iterator find;
        vector<int> ret = vector<int>();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            find = numMap.find(target - nums[i]);
            if (find != numMap.end() && i != find->second)
            {
                ret.push_back(find->second);
                ret.push_back(i);
                return ret;
            }
        }
        return ret;
    }
};