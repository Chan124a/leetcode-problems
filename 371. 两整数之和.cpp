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
    int getSum(int a, int b) {
		while (b)
		{
			auto carry =((unsigned int) a & b) << 1;
			a = a ^ b;
			b = carry;
		}
		return a;
    }
};