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
#include <map>
#include <unordered_map>
#include <time.h>
using namespace std;
class Solution {
public:
    string dfs(vector<string> &ha,int n) {
        if (n == 1)return "1";
        if (n == 2)return "11";
        if (ha[n] != "")return ha[n];
        else {
            string a = dfs(ha, n - 1);
            string ans = "";
            int count=1;
            for (int i = 1; i < a.size(); i++)
            {
                if (a[i] != a[i-1]) {
                    ans += to_string(count);
                    ans += a[i-1];
                    count = 1;
                }
                else {
                    count++;
                }
            }
            ans += to_string(count);
            ans += a[a.size() - 1];
            return ans;
        }
    }
    string countAndSay(int n) {
        vector<string> ha(n+1,"");
        return dfs(ha, n);
    }
};
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}