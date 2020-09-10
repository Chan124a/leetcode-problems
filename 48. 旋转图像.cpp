#include <stack>
#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include <unordered_map>
#include <time.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = matrix.size();
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto& row : matrix)
            reverse(row.begin(), row.end());
    }
};
int main() {
    vector<vector<int>> matrix = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    Solution().rotate(matrix);
    return 0;
}