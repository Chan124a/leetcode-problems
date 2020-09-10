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
        // ��ʼ����Ԫ��Ϊ�����ļ��ϣ�����ڵ�����䱾��
        for (int i = 0; i < sz; i++)
            rp[i] = i;
        for (int j = 0; j < sz; j++) {
            // �ҵ����������ڵ����ڼ��ϵĴ���ڵ�
            int set1 = find(edges[j][0], rp);
            int set2 = find(edges[j][1], rp);
            if (set1 == set2)  // �������ϴ���ڵ���ͬ��˵�����ֻ������ش�
                return edges[j];
            else    // �������϶������ϲ����ϡ���ǰһ�����ϴ���ڵ������һ�����ϴ���ڵ���
                rp[set1] = set2;
        }
        return { 0, 0 };
    }

    // ����·�������ش���ڵ㣬ʵ���Ͼ��Ǹ�����ǰ�ڵ㣬���ظýڵ����ڼ��ϵĴ���ڵ�
    // ֮ǰ����д��ѹ��·�����������壬��Ϊ���û���µ�vector���������ĳ�·�����ұȽϺ���
    // ��л��λ�ϸ������
    int find(int n, vector<int>& rp) {
        int num = n;
        while (rp[num] != num)
            num = rp[num];
        return num;
    }
};
