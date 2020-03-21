#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0; // Pointer
        int strLen = s.length();
        if (strLen == 0) return 0;
        int maxLen = 1;
        while (i < strLen - maxLen)
        {
            set<char> charList;
            charList.insert(s[i]);
            int uniqueOffset;
            for (uniqueOffset = 1; uniqueOffset < strLen - i; uniqueOffset++)
            {
                if (charList.find(s[i + uniqueOffset]) == charList.end()) // Not found
                    charList.insert(s[i + uniqueOffset]);
                else break; // Found
            }
            if (maxLen < uniqueOffset) maxLen = uniqueOffset;
            i++;
        }
        return maxLen;
    }
};


int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring(" 0") << endl;
    return 0;
}