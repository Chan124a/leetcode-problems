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
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        auto graph = build(equations, values);
        vector<double> res;
        for (auto q : queries) {
            set<string> visited;
            bool found = false;
            double r = dfs(graph, visited, q[0], q[1], found);
            if (found)
            {
                res.push_back(r);
                graph[q[0]][q[1]] = r;
                graph[q[1]][q[0]] = 1 / r;
            }
            else
                res.push_back(-1);
        }
        return res;
    }
    unordered_map<string, unordered_map<string, double>> build(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> m;
        for (int i = 0; i < equations.size(); i++)
        {
            vector<string> eqa = equations[i];
            string a = eqa[0];
            string b = eqa[1];
            double v = values[i];
            if (m.find(a)==m.end())
                m[a] = unordered_map<string, double>{ {b,v} };
            else 
                m[a][b] = v;
            if (m.find(b) == m.end())
                m[b] = unordered_map<string, double>{ {a,1 / v} };
            else
                m[b][a] = 1 / v;
        }
        return m;
    }
    double dfs(unordered_map<string, unordered_map<string, double>>& g, set<string> visited, string begin, string end, bool& found) {
        if (g.find(begin)== g.end() || g.find(end) == g.end()) {
            found = false;
            return -1;
        }
        if (visited.find(begin) != visited.end()) {
            found = false;
            return -1;
        }
        if (g[begin].find(end) != g[begin].end()) {
            found = true;
            return g[begin][end];
        }
        visited.insert(begin);
        for (auto it : g[begin]) {
            double r = dfs(g, visited, it.first, end, found);
            if (found)
            {
                double res = r * it.second;
                return res;
            }
        }
        visited.erase(begin);
        found = false;
        return - 1;
    }
};
//class Solution {
//public:
//    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        auto graph = build(equations, values);
//
//        vector<double> res;
//        for (auto q : queries) {
//            set<string> visited;
//            bool found = false;
//            //double r = bfs(graph, visited, q[0], q[1], found);
//            double r = dfs(graph, visited, q[0], q[1], found);
//            if (found) {
//                res.push_back(r);
//                graph[q[0]][q[1]] = r;
//                graph[q[1]][q[0]] = 1 / r;
//            }
//            else {
//                res.push_back(-1);
//            }
//        }
//
//        return res;
//    }
//
//    unordered_map<string, unordered_map<string, double>> build(vector<vector<string>>& equations, vector<double>& values) {
//        unordered_map<string, unordered_map<string, double>> m;
//        for (int i = 0; i < equations.size(); ++i) {
//            vector<string> eqa = equations[i];
//            string a = eqa[0];
//            string b = eqa[1];
//            double v = values[i];
//            if (m.find(a) == m.end()) {
//                m[a] = unordered_map<string, double>{ {b, v} };
//            }
//            else {
//                m[a][b] = v;
//            }
//            if (m.find(b) == m.end()) {
//                m[b] = unordered_map<string, double>{ {a, 1 / v} };
//            }
//            else {
//                m[b][a] = 1 / v;
//            }
//        }
//        return m;
//    }
//
//    double bfs(unordered_map<string, unordered_map<string, double>>& g, set<string> visited, string begin, string end, bool& found) {
//        if (g.find(begin) == g.end() || g.find(end) == g.end()) {
//            found = false;
//            return -1;
//        }
//        queue<pair<string, double>> q;
//        q.push(make_pair(begin, 1));
//        while (!q.empty()) {
//            auto cur = q.front();
//            q.pop();
//            if (visited.find(cur.first) != visited.end()) {
//                continue;
//            }
//            if (cur.first == end) {
//                found = true;
//                return cur.second;
//            }
//            visited.insert(cur.first);
//            for (auto it : g[cur.first]) {
//                q.push(make_pair(it.first, cur.second * it.second));
//            }
//        }
//        found = false;
//        return -1;
//    }
//
//    double dfs(unordered_map<string, unordered_map<string, double>>& g, set<string> visited, string begin, string end, bool& found) {
//        if (g.find(begin) == g.end() || g.find(end) == g.end()) {
//            found = false;
//            return -1;
//        }
//        if (visited.find(begin) != visited.end()) {
//            found = false;
//            return -1;
//        }
//        if (g[begin].find(end) != g[begin].end()) {
//            found = true;
//            return g[begin][end];
//        }
//        visited.insert(begin);
//        for (auto it : g[begin]) {
//            double r = dfs(g, visited, it.first, end, found);
//            if (found) {
//                double res = r * it.second;
//                return res;
//            }
//        }
//        visited.erase(begin);
//        found = false;
//        return -1;
//    }
//};
