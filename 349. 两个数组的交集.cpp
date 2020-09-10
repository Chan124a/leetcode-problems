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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (int a : nums2) {
            if (s.erase(a))res.push_back(a);
        }
        return res;
    }
};

//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//
//        unordered_set<int> m(nums1.begin(), nums1.end());   //将第一个数组的元素建立一个unordered_set
//        vector<int> res;            //建立关于结果的vector
//
//        for (int a : nums2)
//            if (m.erase(a))         //既查找了m中是否存在a,又完成了删除a的工作，避免后续过程重复元素
//                res.push_back(a);       //在vector res的末尾加入a
//
//        return res;
//    }
//};
