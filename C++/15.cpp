#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) return ret;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 2 && nums[i] <= 0)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    vector<int> tmp({nums[i], nums[left], nums[right]});
                    ret.push_back(tmp);
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1]) i++;
            i++;
        }
        return ret;
    }
};

int main()
{
    vector<int> data({0,0,0});
    Solution s;
    auto ans = s.threeSum(data);
    for_each(ans.begin(), ans.end(), 
        [](vector<int> t) -> void {
            for_each(t.begin(), t.end(), [](int x) -> void{cout << x << " ";});
            cout << endl;
        }
    );
    return 0;
}