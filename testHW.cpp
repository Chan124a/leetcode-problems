#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include <set>
#include<vector>
#include<sstream>
using namespace std;
//struct team {
//    char name;
//    int score;
//}te[26];
//bool cmp(team a, team b) {
//    if (a.score != b.score)return a.score > b.score;
//    else return a.name < b.name;
//}
//int main() {
//    map<char, int> ha;
//    string s;
//    int count_team = 0;
//    set<char> name;
//    while (getline(cin, s)) {
//        char teama = s[0], teamb=s[2];
//        int scorea = s[4]-'0', scoreb = s[6] - '0';
//        if (ha.find(teama) == ha.end()) {
//            ha[teama] = count_team;
//            te[count_team].name = teama;
//            count_team++;
//        }
//        if (ha.find(teamb) == ha.end())
//        {
//            ha[teamb] = count_team;
//            te[count_team].name = teamb;
//            count_team++;
//        }
//        if (scorea > scoreb) {
//            te[ha[teama]].score += 3;
//        }
//        else if (scorea == scoreb) {
//            te[ha[teama]].score += 1;
//            te[ha[teamb]].score += 1;
//
//        }
//        else te[ha[teamb]].score += 3;
//    }
//    sort(te, te + count_team, cmp);
//    for (int i = 0; i < count_team; i++) {
//        cout << te[i].name << " " << te[i].score;
//        if (i < count_team - 1)cout << ',';
//        else cout << endl;
//    }
//}
//int main() {
//	string s;
//	getline(cin, s);
//	//stringstream ss(s);
//	vector<int> d;
//	int temp=0;
//	for (int i = 1; i < s.size(); i++)
//	{
//		int c = s[i] - '0';
//		if (c >= 0 && c <= 9) {
//			temp = temp * 10 + c;
//		}
//		else
//		{
//			d.push_back(temp);
//			temp = 0;
//		}
//	}
//	if (d.size() == 0) {
//		cout << 0 << endl;;
//		return 0;
//	}
//	if (d.size() == 1) {
//		cout << d[0] + 1 << endl;;
//		return 0;
//	}
//	sort(d.begin(), d.end());
//	int x = d[0]+1,y=1;
//	//x=2,y=1
//	int ans = 0;
//	for (int i = 1; i <d.size(); i++)
//	{
//		if (d[i] != d[i-1]||y>=x) {
//			ans += x;
//			y = 0;
//			x = d[i] + 1;
//			//x=3
//		}
//		y++;
//		//y=
//	}
//	ans += x;
//	cout << ans << endl;
//	return 0;
//
//}
//
//int main() {
//	string s1, s2;
//	int n;
//	cin >> s1 >> s2 >> n;
//	int len = s1.size();
//	int ans = 0;
//	for (int i = 0; i < s2.size(); i++)
//	{
//		char c = s2[i];
//		int j=n;
//		if (j == s1.size())j = 0;
//		int k = s1.size();
//		int step = 0,mi=INT_MAX;
//		while (k--!=0)
//		{
//			if (s1[j] == c) {
//				if (step < mi || len - step < mi) {
//					mi = min(mi, step);
//					mi = min(mi, len - step);
//					n = j;
//				}
//			}
//			j++;
//			if (j == s1.size())j = 0;
//			step++;
//		}
//		ans += mi;
//	}
//	cout << ans << endl;
//	return 0;
//}
auto* ch() {
	auto* p1, * p2;
	int len1 = 0, len2 = 0;	
	while (p1!=NULL)
	{
		len1++;
	}
	while (p2 != NULL)
	{
		len2++;
	}
	auto* temp1, temp2;
	int k;
	if (len1 >= len2) {
		temp1 = p1;
		temp2 = p2;
		k = len1 - len2;
	}
	else
	{
		temp1 = p2;
		temp2 = p1;
		k = len2 - len1;
	}
	//temp1指向长度比较长的链表
	while (k--!=0)
	{
		temp1 = temp1->next;
	}
	while (temp1!=temp2)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return temp1;
}