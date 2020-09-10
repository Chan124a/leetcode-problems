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
        int i = 0,n=prices.size();
        int min = prices[0], max = prices[0],tatol=0;
        while (i<n)
        {
            while (i<n - 1 && prices[i]>prices[i + 1])i++;
            min = prices[i];
            while (i < n - 1 && prices[i] < prices[i + 1])i++;
            max = prices[i];
            tatol += (max - min);
            i++;
        }
        return tatol;
    }
};