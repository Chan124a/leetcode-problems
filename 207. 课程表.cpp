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
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0)return true;
        vector<vector<int>> lj(numCourses);
        vector<int> rd(numCourses);
        int n = numCourses;
        queue<int> q;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            rd[prerequisites[i][0]]++;
            lj[prerequisites[i][1]].push_back( prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (rd[i] == 0) {
                q.push(i);
                n--;
            }
        }
        while (q.size()!=0)
        {
            int temp = q.front();
            q.pop();
            for (int i = 0; i < lj[temp].size(); i++)
            {
                if (--rd[lj[temp][i]] == 0) {
                    q.push(lj[temp][i]);
                    n--;
                }
            }

        }
        if (n == 0)return true;
        else return false;
    }
};
