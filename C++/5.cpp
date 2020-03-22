#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int strLen = s.length();
        if (strLen == 0) return "";
        int mid = 0, left = 0, right = 0, len = 1;
        bool flag = 0;
        while (strLen - mid > len / 2)
        {
            int i = mid;
            int j = mid + flag;
            mid += flag;
            flag = !flag;
            if (s[i] != s[j]) continue;
            while (i > 0 && j < strLen - 1 && s[i-1] == s[j+1])
            {
                i--;
                j++;
            }
            if (j - i + 1 > len)
            {
                len = j - i + 1;
                left = i;
                right = j;
            }
        }
        return string(&s[left], len);
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("aaabbbb") << endl;
    return 0;
}