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
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)return NULL;
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right)return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid+1, right);
        return mergeTwoList(l1, l2);
    }
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)return l2;
        if (l2 == NULL)return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoList(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoList(l1, l2->next);
            return l2;
        }
    }
};