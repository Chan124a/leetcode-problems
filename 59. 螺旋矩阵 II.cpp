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
    vector<vector<int>> generateMatrix(int n) {
        int fang = 0;
        vector<vector<int>> ans(n,vector<int>(n,0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int count = n* n;
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
                    ans[i][j] = n * n - count+1;
                    visited[i][j] = true;
                    j++;
                    count--;
                }
            }
            else if (fang == 1) {
                if (i == n || visited[i][j]) {
                    fang = 2;
                    j--;
                    i--;
                }
                else {
                    ans[i][j] = n * n - count + 1;
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
                    ans[i][j] = n * n - count + 1;
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
                    ans[i][j] = n * n - count + 1;
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
    vector<vector<int>> ans;
    ans = Solution().generateMatrix(3);
}