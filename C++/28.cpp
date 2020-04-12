// 实现 strStr() 函数。
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        vector<int> next(needle.length());
        // Calculate *next* array, using KMP algo.
        next[0] = 0;
        int k = next[0];
        for (int i = 1; i < needle.length(); i++)
        {
            while (k != 0 && needle[i] != needle[k]) k = next[k - 1];
            if (needle[i] == needle[k]) k++;
            next[i] = k;
        }
        for_each(next.begin(), next.end(), [](int x)-> void{cout << x << " ";});
        cout << endl;
        // Match
        int i = 0;
        int j = 0;
        for (i = 0; i < haystack.length(); i++)
        {
            while (j != 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) j++;
            if (j == needle.length()) return i - j + 1;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("mississippi", "issip") << endl;
    return 0;
}
