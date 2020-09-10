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
using namespace std; 
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)return 0;
        if (m == 1 || n == 1)return 1;
        unsigned  long long int p = 1,q=1;
        if (m > n)swap(m, n);
        for (int i = n; i <= m+n-2; i++)
        {
            p *= i;
        }
        for (int i = 1; i <= m - 1; i++) {
            q *= i;
        }
        return p / q;
        //if (m == 1 || n == 1)
        //    return 1;
        //if (m > n)
        //    swap(m, n);//保证m<=n
        ////计算阶乘：不用调用函数，节省空间
        //unsigned long long int te mp = 1;
        //unsigned long long int result = 1;
        //for (int i = 1; i <= m - 1; i++)
        //{
        //    temp *= i;
        //}
        //for (int i = n; i <= m + n - 2; i++)
        //{
        //    result *= i;
        //}
        //result = result / temp;

    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}