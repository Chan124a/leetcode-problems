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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode khead(0);
        khead.next = head;
        ListNode* p = &khead;
        ListNode* q = &khead;
        while (n--)
        {
            q = q->next;
        }
        while (q->next!=NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return khead.next;
    }
};/*  */