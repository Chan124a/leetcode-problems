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
//对于每一天i，都有可能是三种状态：
//0.不持股且当天没卖出, 定义其最大收益dp[i][0];
//1.持股, 定义其最大收益dp[i][1]；
//2.不持股且当天卖出了，定义其最大收益dp[i][2]；
//
//一、第i天不持股且没卖出的状态dp[i][0]，也就是我没有股票，而且还不是因为我卖了它才没有的，那换句话说是从i - 1天到第i天转移时，它压根就没给我股票！所以i - 1天一定也是不持有，那就是不持有的两种可能：i - 1天不持股且当天没有卖出dp[i - 1][0]；i - 1天不持股但是当天卖出去了dp[i - 1][2]；
//所以： dp[i][0] = max(dp[i - 1][0], dp[i - 1][2])
//
//二、第i天持股dp[i][1]，今天我持股，来自两种可能：
//1、要么是昨天我就持股，今天继承昨天的，也就是dp[i - 1][1]，这种可能很好理解；
//2、要么：是昨天我不持股，今天我买入的，但前提是昨天我一定没卖！因为如果昨天我卖了，那么今天我不能交易！也就是题目中所谓“冷冻期”的含义，只有昨天是“不持股且当天没卖出”这个状态，我今天才能买入！所以是dp[i - 1][0] - p[i]
//所以： dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - p[i])
//
//三、i天不持股且当天卖出了，这种就简单了，那就是说昨天我一定是持股的，要不然我今天拿什么卖啊，而持股只有一种状态，昨天持股的收益加上今天卖出得到的新收益，就是dp[i - 1][1] + p[i]啦
//所以：dp[i][2] = dp[i - 1][1] + p[i]
//
//总结：最后一天的最大收益有两种可能，而且一定是“不持有”状态下的两种可能，把这两种“不持有”比较一下大小，返回即可

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long long d0=0, d1=-prices[0], d2=INT_MIN;
        for (int i = 1; i < prices.size(); i++)
        {
            int c0 = max(d0, d2),
                c1=max(d1,d0-prices[i]),
                c2=d1+prices[i];
            d0 = c0, d1 = c1, d2 = c2;
        }
        return max(d0, d2);
    }
};