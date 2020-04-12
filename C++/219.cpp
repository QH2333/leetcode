#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> container;
        for (int i = 0; i < nums.size(); i++)
        {
            if (container.find(nums[i]) != container.end()) return true;
            container.insert(nums[i]);
            if (container.size() > k) container.erase(nums[i - k]);
        }
        return false;
    }
};

int main()
{
    Solution s;
    return 0;
}