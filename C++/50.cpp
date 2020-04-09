#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool neg = n < 0 ? true : false;
        long long ln = n;
        ln = abs(ln);
        double ret = 1;
        double temp = x;
        while(ln)
        {
            if (ln & 1) ret *= temp;
            temp *= temp;
            ln = ln >> 1;
        }
        if (neg) ret = 1 / ret;
        return ret;
    }
};

// // BF
// class Solution {
// public:
//     double myPow(double x, int n) {
//         double ret = x;
//         if (n < 1)
//         {
//             for (int i = 0; i < (1 - n); i++)
//             {
//                 ret /= x;
//             }
//         }
//         else
//         {
//             for (int i = 0; i < (n - 1); i++)
//             {
//                 ret *= x;
//             }
//         }
//         return ret;
//     }
// };

int main()
{
    Solution s;
    cout << s.myPow(1.00000, -2147483648) << endl;
    return 0;
}