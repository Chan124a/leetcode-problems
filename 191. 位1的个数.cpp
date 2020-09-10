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
    int hammingWeight(uint32_t n) {
		int count = 0;
		while (n!=0)
		{
			if (n & 1)count++;
			n = n >> 1;
		}
		return count;
    }
};