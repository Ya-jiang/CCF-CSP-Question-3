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
struct node {
	string name;
	int level;
	string id;
}css[110];
vector<int> ans[11];

void makecss(int x, string s) {
	string temp = "";
	int pos = 0, l = s.length(), lev = 0;
	while (pos < l && s[pos] == '.') {
		lev++;
		pos++;
	}
	css[x].level = lev >> 1;
	css[x].id = "?";
	while (pos < l && s[pos] != ' ') {
		temp += s[pos];
		pos++;
	}
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	css[x].name = temp;
	if (pos < l && s[pos] == ' ' && s[pos + 1] == '#') {
		pos += 2;
		temp = "#";
		while (pos < l) {
			temp += s[pos];
			pos++;
		}
		css[x].id = temp;
	}
}

int main() {
	//ios::sync_with_stdio(false);
	cin >> n >> m;
	getchar();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		makecss(i, s);
	}
	/*for (int i = 1; i <= n; i++) {
		cout << css[i].name << " " << css[i].id << " " << css[i].level << endl;
	}*/
	for (int i = 1; i <= m; i++) {
		string s;
		getline(cin, s);
		if (s.find(' ') == -1) {
			if (s[0] == '#') {
				for (int j = 1; j <= n; j++) {
					if (css[j].id == s) ans[i].push_back(j);
				}
			}
			else {
				transform(s.begin(), s.end(), s.begin(), ::tolower);
				for (int j = 1; j <= n; j++) {
					if (css[j].name == s) ans[i].push_back(j);
				}
			}
		}
		else {
			stringstream ss;
			ss << s;
			vector<string> stac;
			vector<int> temp;
			int tot = -1;
			while (ss >> s) {
				//cout << s << endl;
				tot++;
				if(s[0]!='#') transform(s.begin(), s.end(), s.begin(), ::tolower);
				stac.push_back(s);
			}
			s = stac[tot];
			if (s[0] == '#') {
				for (int j = 1; j <= n; j++) {
					if (css[j].id == s) temp.push_back(j);
				}
			}
			else {
				for (int j = 1; j <= n; j++) {
					if (css[j].name == s) temp.push_back(j);
				}
			}
			for (auto& j : temp) {
				int k = tot - 1, l = j - 1, lev = css[j].level;
				while (k >= 0 && l >= 0) {
					if (stac[k][0] == '#') {
						if (css[l].id == stac[k] && css[l].level<lev) {
							k--;
							lev = css[l].level;
						}
					}
					else {
						if (css[l].name == stac[k] && css[l].level < lev) {
							k--;
							lev = css[l].level;
						}
					}
					l--;
				}
				if (k < 0) ans[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i].size() << " ";
		for (auto& k : ans[i]) {
			cout << k << " ";
		}
		cout << endl;
	}
	return 0;
}
/*
11 5
html
..HEAD
....title
..boDy
....h1
....p #subtitle
....DIV #main
......h2
......p #one
......div
........p #two
p
#subtitle
h3
div p
div div p
*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/