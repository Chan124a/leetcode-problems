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
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minFlips(int a, int b, int c) {
		int ans = 0;
		while (a!=0||b!=0||c!=0)
		{
			int aa = a & 1, bb = b & 1, cc = c & 1;
			if (cc == 0) {
				if (aa == 1)ans++;
				if (bb == 1)ans++;
			}
			else
			{
				if (aa == 0 & bb == 0)ans++;
			}
			a = a >> 1;
			b = b >> 1;
			c = c >> 1;
		}
		return ans;
    }
};