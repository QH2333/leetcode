#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLen = s.length();
        int maxLen = 0, i = 0, j = 0; // Double pointer
        set<char> charSet;
        while (i < strLen - maxLen)
        {
            while (j < strLen)
            {
                if (charSet.find(s[j]) == charSet.end()) // Not found
                    charSet.insert(s[j++]);
                else break; // Found
            }
            if (maxLen < j - i) maxLen = j - i;
            charSet.erase(s[i++]);
        }
        return maxLen;
    }
};


int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("") << endl;
    return 0;
}