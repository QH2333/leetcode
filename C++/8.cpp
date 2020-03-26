#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int status = 0;
        long ret = 0;
        bool neg = false;
        for (char c: str)
        {
            if (status == 0)
            {
                if (c == ' ') continue;
                else if (c == '+') status = 1;
                else if (c == '-')
                {
                    status = 1;
                    neg = true;
                }
                else if (c >= '0' && c <= '9')
                {
                    status = 2;
                    ret += c - '0';
                }
                else return 0;
            }
            else if (status == 1)
            {
                if (c >= '0' && c <= '9')
                {
                    status = 2;
                    ret += c - '0';
                }
                else return 0;
            }
            else if (status == 2)
            {
                if (c >= '0' && c <= '9')
                {
                    ret *= 10;
                    ret += c - '0';
                    if (!neg && ret > INT_MAX) return INT_MAX;
                    if (neg && -ret < INT_MIN) return INT_MIN;
                }
                else break;
            }
        }
        if (neg) ret = -ret;
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("4193 with words") << endl;
    return 0;
}