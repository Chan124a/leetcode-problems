#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include <set>
#include<vector>
#include<sstream>
//#include <bits/stdc++.h>
using namespace std;


//struct team {
//	vector<int> nan_shuang;
//	vector<int> nv_shuang;
//	int sum;
//};
//team co(vector<int>& te_v,int sum) {
//	team t;
//	t.nan_shuang.push_back(te_v[0] + te_v[1]);
//	t.nan_shuang.push_back(te_v[0] + te_v[2]);
//	t.nan_shuang.push_back(te_v[1] + te_v[2]);
//	t.nv_shuang.push_back(te_v[3] + te_v[4]);
//	t.nv_shuang.push_back(te_v[3] + te_v[5]);
//	t.nv_shuang.push_back(te_v[4] + te_v[5]);
//	t.sum = sum;
//	sort(t.nan_shuang.begin(), t.nan_shuang.end());
//	sort(t.nv_shuang.begin(), t.nv_shuang.end());
//	return t;
//}
//int search(team& t1, team& t2) {
//	int ans = 0;
//	if (t1.nan_shuang[0] >= t2.nan_shuang[2] && t1.nv_shuang[0] >= t2.nv_shuang[2])return 0;
//	int nany = 0, nvy = 0, nannvy = 0;
//	for (int i1 = 0; i1 < 3; i1++)
//	{
//		for (int j1 = 0; j1 < 3; j1++) {
//			for (int  i2 = 0; i2 < 3; i2++)
//			{
//				for (int j2 = 0; j2 < 3; j2++)
//				{
//					int nan_shuang_A = t1.nan_shuang[i1], nv_shuang_A = t1.nv_shuang[j1];
//					int nv_A = t1.sum - nan_shuang_A - nv_shuang_A;
//					int nan_shuang_B = t2.nan_shuang[i2], nv_shuang_B = t2.nv_shuang[j2];
//					int nv_B = t2.sum - nan_shuang_B - nv_shuang_B;
//					int count = 0;
//					if (nan_shuang_B > nan_shuang_A)count++;
//					if (nv_shuang_B > nv_shuang_A)count++;
//					if(nv_B> nv_A)count++;
//					if (count >= 2)ans++;
//				}
//			}
//		}
//	}
//	return ans;
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		team teamA, teamB;
//		vector<int> te_v;
//		int sum=0;
//		for (int i = 0; i < 6; i++)
//		{
//			int temp;
//			cin >> temp;
//			sum += temp;
//			te_v.push_back(temp);
//		}
//		teamA = co(te_v, sum);
//		sum = 0;
//		te_v.clear();
//		for (int i = 0; i < 6; i++)
//		{
//			int temp;
//			cin >> temp;
//			sum += temp;
//			te_v.push_back(temp);
//		}
//		teamB = co(te_v, sum);
//		int ans = search(teamA, teamB);
//		cout << ans << endl;
//	}
//}

int cmp(char A, char B) {
	if (A == 'R') {
		if (B == 'R')return 0;
		else if (B == 'S')return 1;
		else return -1;
	}
	else if (A == 'S') {
		if (B == 'S')return 0;
		else if (B == 'C')return 1;
		else return -1;
	}
	else {
		if (B == 'C')return 0;
		else if (B == 'R')return 1;
		else return -1;
	}
}
//int main() {
//	int T;
//	cin >>T ;
//	for (int i = 0; i < T; i++)
//	{
//		int n, m;
//		cin >> n >> m;
//		vector<char> temp;
//		for (int j = 0; j < n; j++)
//		{
//			char x;
//			cin >> x;
//			temp.push_back(x);
//		}
//		int ans=INT_MIN, sum;
//		for (int j = 0; j < n; j++)
//		{
//			char x = temp[j];
//			sum = n;
//			for (int k = 1; k <= m; k++)
//			{
//				int index = j + k;
//				if (index == n)index = 0;
//				if (index == j)break;
//				char y = temp[index];
//				int t = cmp(x, y);
//				if (t == 0) {
//					x = y;
//				}
//				else if (t == -1) {
//					x = y;
//					sum--;
//				}
//				else
//				{
//					sum--;
//				}
//			}
//			if (sum > ans)ans = sum;
//		}
//		cout << ans << endl;
//	}
//}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n, m;
		cin >> n >> m;
		vector<char> temp;
		vector<int> d(n);
		for (int j = 0; j < n; j++)
		{
			char x;
			cin >> x;
			temp.push_back(x);
			d[j] = j;
		}
		int ans = INT_MIN, sum;
		for (int k = 1; k <=m; k++)
		{
			for (int index = 0; index <n; index++)
			{
				int x = d[index];
				int y = x + 1;


			}
		}
	}
}