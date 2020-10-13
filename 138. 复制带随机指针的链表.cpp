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
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)return NULL;
        Node* p = head;
        while (p != NULL)
        {
            Node* t = p->next;
            p->next = new Node(p->val);
            p->next->next = t;
            p = t;
        }
        p = head;
        while (p != NULL)
        {
            if (p->random == NULL)p->next->random = NULL;
            else  p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        Node* ptr_old_list = head;
        Node* ptr_new_list = head->next;
        Node* result = head->next;
        while (ptr_old_list != NULL)
        {
            ptr_old_list->next = ptr_old_list->next->next;
            if (ptr_new_list->next != NULL)
                ptr_new_list->next = ptr_new_list->next->next;
            else
                ptr_new_list->next = NULL;
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return result;
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

Node* stringToNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    Node* dummyRoot = new Node(0);
    Node* ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new Node(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string NodeToString(Node* node) {
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
        Node* head = stringToNode(line);

        Node* ret = Solution().copyRandomList(head);

        string out = NodeToString(ret);
        cout << out << endl;
    }
    return 0;
}