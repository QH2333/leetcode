#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n - 1 - 2 * i; j++)
            {
                temp = matrix[i][i + j]; // Upper left
                matrix[i][i + j] = matrix[n - 1 - i - j][i]; // Down left
                matrix[n - 1 - i - j][i] = matrix[n - 1 - i][n - 1 - i - j]; // Down right
                matrix[n - 1 - i][n - 1 - i - j] = matrix[i + j][n - 1 - i]; // Upper right 
                matrix[i + j][n - 1 - i] = temp;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> data({{1,2,3}, {4,5,6}, {7,8,9}});
    s.rotate(data);
    return 0;
}