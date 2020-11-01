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
    bool isHappy(int n) {
        unordered_set<int> temp;
        while (n!=1)
        {
            if (temp.find(n) != temp.end())return false;
            temp.insert(n);
            int x=0;
            while (n!=0)
            {
                int y = n % 10;
                x += (y)*y;
                n /= 10;
            }
            n = x;
        }
        return true;
    }
};