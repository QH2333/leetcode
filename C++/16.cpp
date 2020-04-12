#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minVal = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(minVal - target)) minVal = sum;
                if (sum < target) left++;
                else if (sum > target) right--;
                else return sum;
            }
        }
        return minVal;
    }
};

int main()
{
    Solution s;
    vector<int> data = {-1, 2, 1, -4};
    cout << s.threeSumClosest(data, 1) << endl;
    return 0;
}