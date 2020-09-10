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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode khead(0);
        khead.next = head;
        int length = 0;
        ListNode* p = head;
        while (p)
        {
            ++length;
            p = p->next;
        }
        for (int size = 1; size < length; size*=2)
        {
            ListNode* cur = khead.next;
            ListNode* tail= &khead;
            while (cur)
            {
                auto left = cur;
                auto right = cut(left, size);
                cur = cut(right, size);
                tail->next= merge(left, right);
                while (tail->next)
                {
                    tail = tail->next;
                }
            }
        }
        return khead.next;
    }
    ListNode* cut(ListNode* root, int size) {
        auto p = root;
        while (--size&&p)
        {
            p = p->next;
        }
        if (!p)return NULL;
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* p = left, * q = right;
        ListNode khead(0);
        ListNode* ans = &khead;
        while (p&&q)
        {
            if (p->val<q->val)
            {
                ans->next = p;
                ans = ans->next;
                p = p->next;
            }
            else
            {
                ans->next = q;
                ans = ans->next;
                q = q->next;
            }
        }
        ans->next = p ? p:q;
        return khead.next;
    }
};



void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);

        ListNode* ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}