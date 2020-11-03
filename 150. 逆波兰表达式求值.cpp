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
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0)return 0;
        vector<int> stack;
        int count = 0,ans=0;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = stack[stack.size()-1];
                stack.pop_back();
                int b = stack[stack.size()-1];
                stack.pop_back();
                if (tokens[i] == "+") {
                    stack.push_back(a + b);
                }
                else if (tokens[i] == "-")
                {
                    stack.push_back(b - a);
                }
                else if (tokens[i] == "*")
                {
                    stack.push_back(a * b);
                }
                else if (tokens[i] == "/")
                {
                    stack.push_back(b/a);
                }
            }
            else
            {
                stack.push_back( stoi(tokens[i]));
            }
        }
        return stack[0];
    }
};
int main() {
    vector<string> temp = { "4", "13", "5", "/", "+" };
    int ans = Solution().evalRPN(temp);
    return ans;
}