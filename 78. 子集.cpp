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
#include <unordered_map>
#include <time.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    // base case������һ���ռ�
    if (nums.empty()) return { {} };
    // �����һ��Ԫ���ó���
    int n = nums.back();
    nums.pop_back();
    // �ȵݹ����ǰ��Ԫ�ص������Ӽ�
    vector<vector<int>> res = subsets(nums);

    int size = res.size();
    for (int i = 0; i < size; i++) {
        // Ȼ����֮ǰ�Ľ��֮��׷��
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    return res;
}
    
int main() {
    vector<int> s = { 1,2,3 };
    vector<vector<int>> ans = Solution().subsets(s);
    return 0;
}