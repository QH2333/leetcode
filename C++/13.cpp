#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0, str_len = s.length();
        for (int i = 0; i < str_len; i++)
        {
            switch(s[i])
            {
            case 'I':
                if (i < str_len)
                {
                    if (s[i+1] == 'V') {ret += 4; i++; continue;}
                    if (s[i+1] == 'X') {ret += 9; i++; continue;}
                }
                ret += 1;
                break;
            case 'V': ret += 5; break;
            case 'X':
                if (i < str_len)
                {
                    if (s[i+1] == 'L') {ret += 40; i++; continue;}
                    if (s[i+1] == 'C') {ret += 90; i++; continue;}
                }
                ret += 10;
                break;
            case 'L': ret += 50; break;
            case 'C':
                if (i < str_len)
                {
                    if (s[i+1] == 'D') {ret += 400; i++; continue;}
                    if (s[i+1] == 'M') {ret += 900; i++; continue;}
                }
                ret += 100;
                break;
            case 'D': ret += 500; break;
            case 'M': ret += 1000; break;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}