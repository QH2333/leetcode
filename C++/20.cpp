#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int strLen = s.length();
        for (int i = 0; i < strLen; i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') stack.push_back(s[i]);
            else // if (s[i] == ']' || s[i] == ')' || s[i] == '}')
            {
                if (stack.size() == 0) return false;
                else if (stack.back() == '[' && s[i] == ']') stack.pop_back(); // Match
                else if (stack.back() == '(' && s[i] == ')') stack.pop_back(); // Match
                else if (stack.back() == '{' && s[i] == '}') stack.pop_back(); // Match
                else return false; // Not match
            }
        }
        return stack.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("]");
    return 0;
}