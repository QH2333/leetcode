#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

// // 最初方法，使用map，并且map里存储vector里元素的地址
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> ret;
//         ret.reserve(strs.size());
//         map<string, vector<string>*> ans;
//         for (int i = 0; i < strs.size(); i++)
//         {
//             string key = strs[i];
//             sort(key.begin(), key.end());
//             if (ans.find(key) != ans.end()) ans[key]->push_back(strs[i]);
//             else
//             {
//                 ret.push_back(vector<string>());
//                 ret.back().push_back(strs[i]);
//                 ans.insert({ key, &ret.back() });
//             }
//         }
//         return ret;
//     }
// };

// 改进方法，使用unordered_map，并且map里存储vector里元素的下标
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> ans;
        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (ans.find(key) != ans.end()) ret[ans[key]].push_back(strs[i]);
            else
            {
                ret.push_back(vector<string>());
                ret.back().push_back(strs[i]);
                ans.insert({ key, ret.size() - 1 });
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> data({ "eat", "tea", "tan", "ate", "nat", "bat" });
    auto result = s.groupAnagrams(data);
    cout << result.size() << endl;
    return 0;
}