#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x)
        {
            int digit = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10) return 0;
            if (rev < INT_MIN / 10) return 0;
            rev *= 10;
            rev += digit;
        }
        return rev;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(-123) << endl;
    return 0;
}