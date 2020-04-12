#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int>tplt; // Template
    int totalCount = 0;
    int currentCount = 0;
    
    vector<vector<int>> permute(vector<int>& nums) {
        totalCount = nums.size();
        vector<bool> record(totalCount, false);
        recursion(nums, record);
        return ans;
    }
    
    void recursion(vector<int>& nums, vector<bool>& record)
    {
        if (currentCount == totalCount)
        {
            ans.push_back(tplt);
            return;
        }
        for (int i = 0; i < totalCount; i++)
        {
            if (!record[i])
            {
                tplt.push_back(nums[i]);
                record[i] = true;
                currentCount++;
                recursion(nums, record);
                tplt.pop_back();
                record[i] = false;
                currentCount--;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> data({1,2,3,4});
    cout << s.permute(data).size() << endl;
    return 0;
}