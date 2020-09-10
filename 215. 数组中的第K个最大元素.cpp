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
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        int l = 0, r = n - 1;
        srand(time(0));
        while (true)
        {
            int temp = search(nums,l,r);
            if (temp == target)return nums[target];
            else if (temp < target)l = temp + 1;
            else r = temp - 1;
        }
    }
    int search(vector<int>& nums, int left, int right) {
        int x = rand() % (right - left + 1) + left;
        swap(nums[x], nums[left]);
        int p = nums[left];
        int j = left;
        for (int i = left+1; i<=right; i++)
        {
            if (nums[i] < p) {
                j++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[j], nums[left]);
        return j;
    }
};
