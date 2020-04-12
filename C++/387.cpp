#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         unordered_map<int, bool> container;
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (container.find(s[i]) == container.end()) container.insert({s[i], false});
//             else container[s[i]] = true;
//         }
//         for (int i = 0; i < s.length(); i++) if (!container[s[i]]) return i;
//         return -1;
//     }
// };

// Actually we dont need to use unordered_map
class Solution {
public:
    int firstUniqChar(string s) {
        int container[26] = { 0 };
        for (int i = 0; i < s.length(); i++)
        {
            if (container[s[i] - 'a'] == 0) container[s[i] - 'a'] = 1;
            else if (container[s[i] - 'a'] == 1) container[s[i] - 'a'] = 2;
        }
        for (int i = 0; i < s.length(); i++) if (container[s[i] - 'a'] != 2) return i;
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.firstUniqChar("aaab") << endl;
    return 0;
}