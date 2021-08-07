#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include <set>
#include<vector>
#include<sstream>
//#include <bits/stdc++.h>
using namespace std;


//struct ListNode {
//int val;
//struct ListNode *next;
//};
//
//
////ListNode* reverse(ListNode* root) {
////    ListNode* ans = root;
////    while (root->next!=NULL)
////    {
////        ListNode* temp = root->next->next;
////        ans = root->next;
////        root->next->next = root;
////        root->next = temp;
////
////    }
////    return ans;
////}
//class Solution {
//public:
//    /**
//    代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//    @param S ListNode类 val表示权值，next指向下一个元素
//    @return ListNode类
//     */
//    bool cmp(ListNode* p1, ListNode* p2) {
//        if (p1 == NULL && p2 == NULL)return 0;
//        if (p1->val != p2->val)return p1->val < p2->val;
//        else return cmp(p1->next, p2->next);
//    }
//    ListNode* solve(ListNode* S) {
//        if (S == NULL)return NULL;
//        if (S->next == NULL)return S;
//        // write code here
//        //S=reverse(S);
//        ListNode khead;
//        ListNode* p1=&khead;
//        ListNode* t = S;
//        ListNode* wb;
//        int len = 0;
//        while (t!=NULL)
//        {
//            if (t->next == NULL)wb = t;
//            ListNode* temp = new ListNode;
//            temp->val = t->val;
//            temp->next = t->next;
//            p1->next = temp;
//            p1 = p1->next;
//            t = t->next;
//            len++;
//        }
//        p1 = &khead;
//        for (int i = 0; i < len-1; i++)
//        {
//            ListNode* temp = S->next;
//            wb->next = S;
//            S->next = NULL;
//            S = temp;
//            if (cmp(p1->next, S))khead.next = S;
//        }
//        return khead.next;
//    }
//};

struct game {
	int time;
	int score;
};
bool cmp(game& g1, game& g2) {
	if (g1.time != g2.time)return g1.time < g2.time;
	else return g1.score > g2.score;
}
int main() {
	int T;
	cin >> T;
	while (T--!=0)
	{
		int n;
		cin >> n;
		vector<game> games;
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			game temp;
			temp.time = t;
			games.push_back(temp);
		}
		for (int i = 0; i < n; i++)
		{
			int s;
			cin >> s;
			games[i].score = s;
		}
		sort(games.begin(), games.end(), cmp);
		int t = 0,ans=0;
		for (int i = 0; i < n; i++)
		vector<int> d;
		{
			if (t < games[i].time)t++;
			else ans += games[i].score;
		}

	}
}