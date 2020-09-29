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
    bool dfs(vector<int>& gas, vector<int>& cost,int start,int index,int count){
        //if (next == start)return true;
        int temp = count + gas[index] - cost[index];
        if ( temp>= 0) {
            if (index == gas.size() - 1)index = 0;
            else index = index + 1;
            if (index == start)return true;
            else return dfs(gas, cost, start, index, temp);
        }
        else return false;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); i++)
        {
            if (dfs(gas, cost, i, i, 0))return i;
        }
        return -1;
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
        vector<int> gas = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> cost = stringToIntegerVector(line);

        int ret = Solution().canCompleteCircuit(gas, cost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}