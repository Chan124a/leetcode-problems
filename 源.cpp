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
int main() {
	//³ÂÅà¶«
	//ÊÖ»úºÅ£º13902544653
	vector<int> num;
	vector<bool> ha(n+1);
	for (int  i = 0; i < num.size(); i++)
	{
		ha[num[i]] = true;
	}
	for (int  i = 0; i < n+1; i++)
	{
		if (!ha[i])return i;
	}

}