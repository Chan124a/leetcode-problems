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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)return false;
        if (matrix[0].size() == 0)return false;
        int m = matrix.size(), n = matrix[0].size();
        if (target > matrix[m - 1][n - 1] || target < matrix[0][0])return false;
        int left = 0, right = m - 1;
        while (left<right)
        {
            int mid = (left + right) / 2;
            if (matrix[mid][0] < target)left = mid + 1;
            else right = mid;
        }
        if (matrix[left][0] > target)left--;
        if (matrix[left][0] == target)return true;
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++)
        {
            int mid = (l + r) / 2;
            if (matrix[left][mid] == target)return true;
            else if (matrix[left][mid] < target)l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};