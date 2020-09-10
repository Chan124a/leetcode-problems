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
using namespace std;
class KthLargest {
    multiset<int> st;
    int x;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            st.insert(n);
            if (st.size() > k)st.erase(st.begin());
        }
        x = k;
    }

    int add(int val) {
        st.insert(val);
        if (st.size() > x)st.erase(st.begin());
        return *st.begin();
    }
};
////下面是用小顶堆的方法解决
//class KthLargest {
//    priority_queue<int, vector<int>, greater<int>> pq;
//    int x;
//public:
//    KthLargest(int k, vector<int>& nums) {
//        for (int n : nums) {
//            pq.push(n);
//            if (pq.size() > k)pq.pop();
//        }
//        x = k;
//    }
//
//    int add(int val) {
//        pq.push(val);
//        if (pq.size() > x)pq.pop();
//        return pq.top();
//    }
//};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */