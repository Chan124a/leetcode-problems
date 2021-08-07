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
    vector<int> countBits(int num) {
		vector<int> ans;
		for (int i = 0; i <= num; i++)
		{
			if (i == 0){
				ans.push_back(0);
				continue;
			}
			if (i % 2 == 0)ans.push_back(ans[i >> 1]);
			else ans.push_back(ans[i - 1]);
		}
		return ans;
    }
};