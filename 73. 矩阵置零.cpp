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
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size()==0)return;
        if (matrix[0].size() == 0)return;
        int m = matrix.size(), n = matrix[0].size();
        bool r_flag = false, c_flag = false;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0]==0)c_flag = true;
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)r_flag = true;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)continue;
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (r_flag)
            for (int j = 0; j < n; j++)matrix[0][j] = 0;
        if (c_flag)
            for (int i = 0; i < m; i++)matrix[i][0] = 0;
        return;
    }
};
