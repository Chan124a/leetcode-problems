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
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)return false;
        int m = matrix.size()-1, n = 0;
        while (m>=0&&m<matrix.size()&&n>=0&&n<matrix[0].size())
        {
            if (matrix[m][n] == target)return true;
            if (matrix[m][n] > target)m--;
            else n++;
        }
        return false;
    }
};
int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    bool flag = Solution().searchMatrix(matrix,5);

}