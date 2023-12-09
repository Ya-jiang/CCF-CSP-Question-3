/*#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<functional>*/
#include<bits/stdc++.h>
//#define re register
typedef long long ll;
//typedef unsigned long long ull;
//#define inf INT32_MAX
//std::numeric_limits<int>::max()
//_LINE_  _TIME_  _DATE_
using namespace std;
const int M = 1000000000+1;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
//const int inf = 2147483647;
//const double eps = 1e-9;
/*int read() {
	int res = 0, k = 1;
	char c = getchar();
	while ((c < '0' || c>'9') && c != '-') c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') res = (res<<3) + (res<<1) + c - '0', c = getchar();
	return res * k;
}
ll llread() {
	ll res = 0LL, k = 1LL;
	char c = getchar();
	while ((c < '0' || c>'9') && c != '-') c = getchar();
	if (c == '-') k = -k, c = getchar();
	while (c >= '0' && c <= '9') res = res * 10LL + ((ll)c - (ll)'0'), c = getchar();
	return res * k;
}
void Exgcd(ll a, ll b, ll& x, ll& y) {
	if (!b) x = 1, y = 0;
	else Exgcd(b, a % b, y, x), y -= a / b * x;
}

int getine(int a, int p) {//a%p意义下的逆元
	ll x, y;
	Exgcd(a, p, x, y);
	x = (x % p + p) % p;
	return x;
}*/

int n, m;
string url[110], ying[110];

pair<string,int> cut(string s, int& pos) {
	string ss = "";
	int l = s.length(), type = 1;
	while (pos < l && s[pos] != '/') {
		ss += s[pos];
		if (s[pos] > '9' || s[pos] < '0') type = 0;
		pos++;
	}
	if (type) {
		while (ss.length() > 1 && ss[0] == '0') {
			ss.erase(ss.begin());
		}
	}
	pos++;
	return make_pair(ss, type);
}

void ope(string s) {
	int l1 = s.length();
	for (int i = 1; i <= n; i++) {
		if (s == url[i]) {
			cout << ying[i] << endl;
			return;
		}
		int l2 = url[i].length();
		int p1 = 0, p2 = 0;
		if (url[i][l2 - 1] == '/' && s[l1 - 1] != '/' || url[i][l2 - 1] != '/' && s[l1 - 1] == '/') continue;
		vector<string> ans;
		while (p1 < l1 && p2 < l2) {
			if (url[i][p2] == '<') {
				if (url[i][p2+1] == 'p') {
					cout << ying[i] << " ";
					for (auto& k : ans) cout << k << " ";
					cout<<s.substr(p1, l1 - p1) << endl;
					return;
				}
				else {
					bool judge = 1;
					while (p1 < l1 && p2 < l2) {
						if (url[i][p2] != '<') break;
						if (url[i][p2 + 1] == 'p') {
							cout << ying[i] << " ";
							for (auto& k : ans) cout << k << " ";
							cout << s.substr(p1, l1 - p1) << endl;
							return;
						}
						pair<string, int> temp = cut(s, p1);
						if (temp.second == 1 && url[i][p2 + 1] == 'i' || temp.second == 0 && url[i][p2 + 1] == 's') {
							ans.push_back(temp.first);
							p2 += 6;
						}
						else {
							judge = 0;
							p2 = l2+1;
							break;
						}
					}
					if (judge && p1 >= l1 && p2 >= l2) {
						cout << ying[i] << " ";
						for (auto& k : ans) cout << k << " ";
						cout << endl;
						return;
					}
				}
			}
			else if (s[p1] != url[i][p2]) break;
			else p1++, p2++;
		}
		if (p1 == l1 && p2 == l2) {
			cout << ying[i] << " ";
			for (auto& k : ans) cout << k << " ";
			cout << endl;
			return;
		}
	}
	cout << "404" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> url[i] >> ying[i];
	}
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		ope(s);
	}
	return 0;
}
/*
6 5
/articles/2003/ special_case_2003
/articles/<int>/ year_archive
/articles/<int>/<int>/ month_archive
/articles/<int>/<int>/<str>/ article_detail
/articles/<int>/<int>/<str>/0articles/2003/<path> article_detail666
/static/<path> static_serve
/articles/<int>/<int>/<str>/<path> article_detail
/articles/2004/
/articles/1985/09/aloha/
/articles/hello/
/static/js/jquery.js
/articles/00001985/00009/000aloha/00001985/00009/aloha
/articles/00001985/00009/000aloha/0articles/2003/00001985/00009/aloha

1 1
/articles/<int>/<int>/<str>/0articles/2003/<path> article_detail666
/articles/00001985/00009/000aloha/0articles/2003/00001985/00009/aloha

1 1
/articles/<int>/<int>/<str>/0articles/2003/ article_detail666
/articles/00001985/00009/000aloha/0articles/2003/
*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/