#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string* line = new string[numRows];
        int pointer = 0;
        int direction = 1;
        for (int i = 0; i < s.length(); i++)
        {
            line[pointer] += s[i];
            if (pointer == numRows - 1 && direction == 1) direction = -1;
            if (pointer == 0 && direction == -1) direction = 1;
            pointer += direction;
        }
        string ret;
        for (int i = 0; i < numRows; i++) ret += line[i];
        delete[] line;
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.convert("LEETCODEISHIRING", 4) << endl;
    return 0;
}