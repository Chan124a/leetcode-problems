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
using namespace std;
class Solution {
public:
    bool isUgly(int num) {
		if (num == 1)return true;
		if (num == 0)return false;
		while ((num%2==0||num%3==0||num%5==0)&&num!=1)
		{
			if (num % 2 == 0)num /= 2;
			else if (num % 3 == 0)num /= 3;
			else if (num % 5 == 0)num /= 5;
		}
		if (num == 1)return true;
		else return false;
    }
};