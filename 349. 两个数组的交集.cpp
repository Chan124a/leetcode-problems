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
//        unordered_set<int> m(nums1.begin(), nums1.end());   //����һ�������Ԫ�ؽ���һ��unordered_set
//        vector<int> res;            //�������ڽ����vector
//
//        for (int a : nums2)
//            if (m.erase(a))         //�Ȳ�����m���Ƿ����a,�������ɾ��a�Ĺ�����������������ظ�Ԫ��
//                res.push_back(a);       //��vector res��ĩβ����a
//
//        return res;
//    }
//};
