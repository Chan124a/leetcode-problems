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
#include <unordered_set>
#include <unordered_map>
#include <time.h>
#include <map>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#')return;
        board[i][j] = '#';
        dfs(board, i - 1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
        dfs(board, i+1, j);
        return;
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool isEdge = i == 0 || j == 0 || i == m - 1 || j == n - 1;
                if (isEdge && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')board[i][j] = 'X';
                if (board[i][j] == '#')board[i][j] = 'O';
            }
        }
    }
};