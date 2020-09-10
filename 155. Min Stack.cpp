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
using namespace std;
class MinStack {
    stack<int> sta1;
    stack<int> sta2;
public:
    /** initialize your data structure here. */
    MinStack() {
        sta2.push(INT_MAX);
    }

    void push(int x) {
        sta1.push(x);
        sta2.push(min(sta2.top(), x));
    }

    void pop() {
        sta1.pop();
        sta2.pop();
    }

    int top() {
        return sta1.top();
    }

    int getMin() {
        return sta2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */