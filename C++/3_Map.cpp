#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLen = s.length();
        int maxLen = 0, i = 0, j = 0; // Double pointer
        map<char, int> charMap;
        for (j = 0; j < strLen; j++)
        {
            if (charMap.find(s[j]) != charMap.end()) // Found
            {
                int keyPos = charMap.find(s[j])->second;
                if (keyPos > i) i = keyPos;
                charMap.erase(s[j]);
            }
            charMap.insert(pair<char, int>(s[j], j + 1)); // If char at pos k equals s[j], then i will be set to j + 1
            if (maxLen < j - i + 1) maxLen = j - i + 1;
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