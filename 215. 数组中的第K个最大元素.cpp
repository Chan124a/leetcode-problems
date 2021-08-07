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
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        int n = nums.size();
//        int target = n - k;
//        int l = 0, r = n - 1;
//        srand(time(0));
//        while (true)
//        {
//            int temp = search(nums,l,r);
//            if (temp == target)return nums[target];
//            else if (temp < target)l = temp + 1;
//            else r = temp - 1;
//        }
//    }
//    int search(vector<int>& nums, int left, int right) {
//        int x = rand() % (right - left + 1) + left;
//        swap(nums[x], nums[left]);
//        int p = nums[left];
//        int j = left;
//        for (int i = left+1; i<=right; i++)
//        {
//            if (nums[i] < p) {
//                j++;
//                swap(nums[j], nums[i]);
//            }
//        }
//        swap(nums[j], nums[left]);
//        return j;
//    }
//};

//¶ÑÅÅÐò
class Solution {
public:
    void dd(vector<int>& nums, int i,int n) {
        int l = i * 2 + 1, r = i * 2 + 2,largest=i;
        if (l<n&& nums[l] > nums[largest])largest = l;
        if (r<n&& nums[r] > nums[largest])largest = r;
        if (largest != i) {
            swap(nums[i], nums[largest]);
            dd(nums, largest,n);
        }
    }
    void build(vector<int>& nums) {
        for (int i = nums.size()/2; i>=0;i--)
        {
            dd(nums, i,nums.size());
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        build(nums);
        int size = nums.size();
        for (int i = 0; i < k; i++)
        {
            swap(nums[0], nums[size - 1 - i]);
            dd(nums, 0, size - i -1);
        }
        return nums[size - k];
    }
};
