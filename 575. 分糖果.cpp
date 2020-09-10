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
#include <unordered_map>
using namespace std;
//下面两种解法都是一样的，复杂度也差不多
//class Solution {
//public:
//    int distributeCandies(vector<int>& candies) {
//        unordered_map<int, int> ha;
//        int n = candies.size();
//        int count = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (ha.count(candies[i]) == 0) {
//                ha[candies[i]] = 1;
//                count++;
//            }
//            else ha[candies[i]]++;
//        }
//        n = n / 2;
//        if (count >= n)return n;
//        else return count;
//    }
//};
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> ha;
        int n = candies.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (ha.count(candies[i]) == 0) {
                ha.insert(candies[i]);
                count++;
            }
        }
        n = n / 2;
        if (count >= n)return n;
        else return count;
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
        vector<int> candies = stringToIntegerVector(line);

        int ret = Solution().distributeCandies(candies);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}