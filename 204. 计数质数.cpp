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
#include <unordered_set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <math.h>
#include <bitset>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> prime(n + 1, false);
        //for (int i = 0; i < n; i++)prime[i] = true;
        for (int i = 2; i <=sqrt(n); i++)
        {
            if (!prime[i]) {
                for (int j = i*i; j <n; j+=i)
                {
                    prime[j] = true;
                }
            }
        }
        for (int i = 2; i <n; i++)
        {
            if (!prime[i])res++;
        }
        return res;
    }
};