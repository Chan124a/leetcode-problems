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
#include <map>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode khead(0);
        khead.next = head;
        ListNode* p = &khead;
        while (p->next!=NULL&&p->next->next!=NULL)
        {
            ListNode* q = p->next->next;
            p->next->next = p->next->next->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
        return khead.next;
    }
};