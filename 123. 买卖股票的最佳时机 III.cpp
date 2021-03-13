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

//一天结束时，可能有持股、可能未持股、可能卖出过1次、可能卖出过2次、也可能未卖出过
//
//所以定义状态转移数组dp[天数][当前是否持股][卖出的次数]
//
//具体一天结束时的6种状态：
//
//1.未持股，未卖出过股票：说明从未进行过买卖，利润为0
//dp[i][0][0] = 0
//2.未持股，卖出过1次股票：可能是今天卖出，也可能是之前卖的（昨天也未持股且卖出过）
//dp[i][0][1] = max(dp[i - 1][1][0] + prices[i], dp[i - 1][0][1])
//3.未持股，卖出过2次股票:可能是今天卖出，也可能是之前卖的（昨天也未持股且卖出过）
//dp[i][0][2] = max(dp[i - 1][1][1] + prices[i], dp[i - 1][0][2])
//4.持股，未卖出过股票：可能是今天买的，也可能是之前买的（昨天也持股）
//dp[i][1][0] = max(dp[i - 1][0][0] - prices[i], dp[i - 1][1][0])
//5.持股，卖出过1次股票：可能是今天买的，也可能是之前买的（昨天也持股）
//dp[i][1][1] = max(dp[i - 1][0][1] - prices[i], dp[i - 1][1][1])
//6.持股，卖出过2次股票：最多交易2次，这种情况不存在
//dp[i][1][2] = float('-inf')


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long long d00 = 0, d01 = INT_MIN, d02 = INT_MIN, d10 = -prices[0], d11 = INT_MIN;
        for (int i = 1; i <prices.size(); i++)
        {
            int c00 = 0,
                c01 = max(d10 + prices[i], d01),
                c02 = max(d11 + prices[i], d02),
                c10 = max(d00 - prices[i], d10),
                c11 = max(d01 - prices[i], d11);
            d00= c00, d01=c01, d02=c02, d10=c10, d11 = c11;
        }
        return max(d00, max(d01, d02));
    }
};
void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);

        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}