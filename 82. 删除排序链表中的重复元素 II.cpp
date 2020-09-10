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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)return head;
        ListNode khead(0);
        khead.next = head;
        ListNode* p = &khead;
        ListNode* q = head;
        while (q!=NULL)
        {
            if (q->next != NULL && q->next->val == q->val) {
                int temp = q->val;
                while (q!=NULL&&temp==q->val)
                {
                    q = q->next;
                }
            }
            else
            {
                p->next = q;
                p = q;
                q = q->next;
            }
        }
        p->next = q;
        return khead.next;
    }
};