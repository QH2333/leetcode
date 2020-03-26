#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        return getMax(nums, 0, nums.size() - 1);
    }

private:
    int getMax(vector<int>& nums, int i, int j)
    {
        if (i == j) return nums[i];
        int mid = (i + j) / 2;
        int leftMax = getMax(nums, i, mid);
        int rightMax = getMax(nums, mid + 1, j);
        int crossMax = nums[mid];
        int tempSum = 0;
        int tempMax = 0;
        for (int k = mid - 1; k >= i; k--)
        {
            tempSum += nums[k];
            if (tempSum > tempMax) tempMax = tempSum;
        }
        crossMax += tempMax;
        tempSum = 0;
        tempMax = 0;
        for (int k = mid + 1; k <= j; k++)
        {
            tempSum += nums[k];
            if (tempSum > tempMax) tempMax = tempSum;
        }
        crossMax += tempMax;
        int ret = leftMax > rightMax ? leftMax : rightMax;
        return crossMax > ret ? crossMax : ret;
    }
};

int main()
{
    vector<int> data({-84,-87,-78,-16,-94,-36,-87,-93,-50,-22,-63,-28,-91,-60,-64,-27,-41,-27,-73,-37,-12,-69,-68,-30,-83,-31,-63,-24,-68,-36,-30,-3,-23,-59,-70,-68,-94,-57,-12,-43,-30,-74,-22,-20,-85,-38,-99,-25,-16,-71,-14,-27,-92,-81,-57,-74,-63,-71,-97,-82,-6,-26,-85,-28,-37,-6,-47,-30,-14,-58,-25,-96,-83,-46,-15,-68,-35,-65,-44,-51,-88,-9,-77,-79,-89,-85,-4,-52,-55,-100,-33,-61,-77,-69,-40,-13,-27,-87,-95,-40});
    Solution s;
    cout << s.maxSubArray(data) << endl;
    return 0;
}