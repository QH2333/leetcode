#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long rem = abs((long long)dividend);
        long long divs = abs((long long)divisor);
        long long quotient = 0;
        while (rem >= divs)
        {
            long long partialQuotient = 1;
            long long partialDivs = divs;
            while (rem >= partialDivs)
            {
                partialQuotient <<= 1;
                partialDivs <<= 1;
            }
            partialQuotient >>= 1;
            partialDivs >>= 1;
            quotient += partialQuotient;
            rem -= partialDivs;
        }
        cout << quotient << endl;
        cout << negative << endl;
        if (negative) quotient *= -1;
        return quotient;
    }
};

int main()
{
    Solution s;
    cout << s.divide(INT_MIN, 1) << endl;
    return 0;
}