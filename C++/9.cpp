#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x && !(x % 10)))
            return false;
        int rev = 0;
        while (x > rev)
        {
            int digit = x % 10;
            x /= 10;
            rev *= 10;
            rev += digit;
        }
        if (x == rev)
            return true;
        if (x == rev / 10)
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome(-123) << endl; // false
    cout << s.isPalindrome(0) << endl;    // true
    cout << s.isPalindrome(10) << endl;   // false
    cout << s.isPalindrome(12) << endl;   // false
    cout << s.isPalindrome(121) << endl;  // true
    cout << s.isPalindrome(1221) << endl; // true
    cout << s.isPalindrome(1222) << endl; // false
    return 0;
}