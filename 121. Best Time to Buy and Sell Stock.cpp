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
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)return 0;
        int max = 0, minprices = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            int t = prices[i] - minprices;
            if (t > max)max = t;
            if (minprices > prices[i])minprices = prices[i];
        }
        return max;
    }
};