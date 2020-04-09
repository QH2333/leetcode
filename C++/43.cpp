#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string multiplicand = num1.length() >= num2.length() ? num1 : num2;
        string multiplier = num1.length() < num2.length() ? num1 : num2;
        string sum = "0";
        int trailingZeros = 0;
        for (int i = multiplier.length() - 1; i >= 0; i--)
        {
            string temp;
            if (multiplier[i] == '0')
            {
                // Do nothing
            }
            else if (multiplier[i] == '1')
            {
                temp = multiplicand;
                temp.append(string(trailingZeros, '0'));
            }
            else
            {
                temp = "0" + multiplicand;
                int carry = 0;
                int times = multiplier[i] - '0';
                for (int j = temp.length() - 1; j >=  0; j--)
                {
                    int calcUnit = (temp[j] - '0') * times + carry;
                    temp[j] = (calcUnit % 10) + '0';
                    carry = calcUnit / 10;
                }
                temp.append(string(trailingZeros, '0'));
            }
            string newSum = "";
            int p1 = sum.length() - 1;
            int p2 = temp.length() - 1;
            int carry = 0;
            while (p1 >= 0 && p2 >= 0)
            {
                int calcUnit = sum[p1--] + temp[p2--] - '0' * 2 + carry;
                carry = calcUnit / 10;
                newSum.insert(0, 1, (calcUnit % 10) + '0');
            }
            while (p1 != -1)
            {
                int calcUnit = sum[p1--] - '0' + carry;
                carry = calcUnit / 10;
                newSum.insert(0, 1, (calcUnit % 10) + '0');
            }
            while (p2 != -1)
            {
                int calcUnit = temp[p2--] - '0' + carry;
                carry = calcUnit / 10;
                newSum.insert(0, 1, (calcUnit % 10) + '0');
            }
            if (carry) newSum.insert(0, 1, '1');
            sum = newSum;
            trailingZeros++;
        }
        while (sum[0] == '0' && sum.length() > 1) sum.erase(0, 1);
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.multiply("584", "18") << endl;
    return 0;
}