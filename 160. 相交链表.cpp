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
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int l1 = 0, l2 = 0;
        ListNode* p = headA;
        while (p != NULL)
        {
            l1++;
            p = p->next;
        }
        p = headB;
        while (p != NULL)
        {
            l2++;
            p = p->next;
        }
        ListNode* p1 = headA, * p2 = headB;
        if (l1 > l2) {
            int k = l1 - l2;
            while (k != 0)
            {
                p1 = p1->next;
                k--;
            }
        }
        else
        {
            int k = l2 - l1;
            while (k != 0)
            {
                p2 = p2->next;
                k--;
            }
        }
        while (p1 != NULL && p2 != NULL)
        {
            if (p1 == p2)return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};