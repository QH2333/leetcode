#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string templ = strs[0];
        int commonLen = templ.length();
        for (auto iter = strs.begin()++; iter != strs.end(); iter++)
        {
            for (int i = 0; i < commonLen; i++)
            {
                if (templ[i] != (*iter)[i])
                {
                    commonLen = i;
                    break;
                }
            }
        }
        return string(templ, 0, commonLen);
    }
};

int main()
{
    Solution s;
    vector<string> testCase;
    cout << s.longestCommonPrefix(testCase) << endl;
    return 0;
}