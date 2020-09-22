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
#include <map>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        for (int i = 0; i <= rowIndex; i++) {
            if (i == 0)ans.push_back({ 1 });
            else
            {
                vector<int> temp;
                for (int j = 0; j <= i; j++) {
                    if (j == 0 || j == i)temp.push_back(1);
                    else
                    {
                        temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                    }
                }
                ans.push_back(temp);
            }
        }
        return ans[rowIndex];
    }
};