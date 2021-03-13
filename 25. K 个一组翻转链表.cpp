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
#include <bitset>
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
    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* pre = NULL, * cur = a, * next = NULL;
        while (cur!=b)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)return NULL;
        ListNode* a = head, *b = head;
        for (int i = 0; i < k; i++)
        {
            if (b == NULL)return head;
            b = b->next;
        }
        head = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return head;
    }
};