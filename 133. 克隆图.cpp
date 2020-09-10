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

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* used[101];
    Node* cloneGraph(Node* node) {
        if (!node)return node;
        if (used[node->val])return used[node->val];
        Node* p = new Node(node->val);
        used[p->val] = p;
        vector<Node*> pt = node->neighbors;
        for (int i = 0; i < pt.size(); i++)
        {
            p->neighbors.push_back(cloneGraph(pt[i]));
        }
        return p;
    }
};

