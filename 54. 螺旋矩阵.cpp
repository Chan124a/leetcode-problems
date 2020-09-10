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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int fang = 0;
        if (matrix.size() == 0)return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int count = m * n;
        int i = 0, j = 0;
        while (count)
        {
            if (fang == 0) {
                if (j == n || visited[i][j]) {
                    fang = 1;
                    i++;
                    j--;
                }
                else {
                    ans.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    j++;
                    count--;
                }
            }
            else if (fang == 1) {
                if (i == m || visited[i][j]) {
                    fang = 2;
                    j--;
                    i--;
                }
                else {
                    ans.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    i++;
                    count--;
                }
            }
            else if (fang == 2) {
                if (j == -1 || visited[i][j]) {
                    fang = 3;
                    j++;
                    i--;
                }
                else {
                    ans.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    j--;
                    count--;
                }
            }
            else {
                if (i == 0 || visited[i][j]) {
                    fang = 0;
                    i++;
                    j++;
                }
                else {
                    ans.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    i--;
                    count--;
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    vector<int> ans;
    ans = Solution().spiralOrder(matrix);
}