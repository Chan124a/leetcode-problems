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
using namespace std;
class Solution {
public:
	string convertToTitle(int n) {
		string ans;
		while (n != 0)
		{
			n--;
			char c = n% 26 + 'A';
			string temp(1, c);
			ans = temp + ans;
			n /= 26;
		}
		return ans;
	}
};
int main() {
	string ans = Solution().convertToTitle(701);
}