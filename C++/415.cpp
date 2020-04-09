#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string retVal = "";
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        int carry = 0;
        while (p1 >= 0 || p2 >= 0)
        {
            int calcUnit = carry;
            if (p1 >= 0) calcUnit += num1[p1--] - '0';
            if (p2 >= 0) calcUnit += num2[p2--] - '0';
            carry = calcUnit / 10;
            retVal.insert(0, 1, (calcUnit % 10) + '0');
        }
        if (carry) retVal.insert(0, 1, '1');
        return retVal;
    }
};