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
#include <map>
using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> m(n+2);
        for (int i = 1; i < n+1; i++)
        {
            m[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int f1 = find(edges[i][0],m);
            int f2 = find(edges[i][1],m);
            if (f1 == f2)return edges[i];
            else m[f1] = f2;
        }
        return { 0,0 };
    }
    int find(int root,vector<int> m) {
        //int a = root;
        while (m[root]!=root)
        {
            //a = m[a];
            root = m[root];
        }
        return root;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> rp(1001);
        int sz = edges.size();
        // 初始化各元素为单独的集合，代表节点就是其本身
        for (int i = 0; i < sz; i++)
            rp[i] = i;
        for (int j = 0; j < sz; j++) {
            // 找到边上两个节点所在集合的代表节点
            int set1 = find(edges[j][0], rp);
            int set2 = find(edges[j][1], rp);
            if (set1 == set2)  // 两个集合代表节点相同，说明出现环，返回答案
                return edges[j];
            else    // 两个集合独立，合并集合。将前一个集合代表节点戳到后一个集合代表节点上
                rp[set1] = set2;
        }
        return { 0, 0 };
    }

    // 查找路径并返回代表节点，实际上就是给定当前节点，返回该节点所在集合的代表节点
    // 之前这里写的压缩路径，引起歧义，因为结果没更新到vector里，所以这里改成路径查找比较合适
    // 感谢各位老哥的提议
    int find(int n, vector<int>& rp) {
        int num = n;
        while (rp[num] != num)
            num = rp[num];
        return num;
    }
};
