#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; i++) // Repeat n-1 times
        {
            string temp = "";
            char currChar;
            char len = '0'; // Won't be greater than 9
            for (int i = 0; i< ans.length(); i++)
            {
                if (len == '0') // Init
                {
                    currChar = ans[i];
                    len = '1';
                }
                else
                {
                    if (currChar == ans[i]) len++;
                    else
                    {
                        temp += len;
                        temp += currChar;
                        currChar = ans[i];
                        len = '1';
                    }
                }
            }
            temp += len;
            temp += currChar;
            ans = temp;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(30) << endl;
    return 0;
}