#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<bool> container(nums.size() + 1, false);
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!container[nums[i]]) container[nums[i]] = true;
            else ans.push_back(nums[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    return 0;
}