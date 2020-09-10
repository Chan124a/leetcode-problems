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
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pq;
        for (int n : stones) {
            pq.push(n);
        }
        while (pq.size()!=1&&pq.size()!=0)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y)pq.push(x - y);
        }
        if (pq.size()==0)
        {
            return 0;
        }
        return pq.top();
    }
};