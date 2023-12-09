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
	//cout << x << " " << y << endl;
}

ll getine(ll a, ll p) {//a%p意义下的逆元
	ll x, y;
	Exgcd(a, p, x, y);
	x = (x % p + p) % p;
	return x;
}
*/

string rule;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin >> rule;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 1; i <= n; i++) {
		getline(cin, s);
		stringstream ss;
		ss << s;
		ss >> s;
		char last = '?';
		map<char, string> para;
		set<char> ans;
		bool p = 0;
		while (ss >> s) {
			if (s[0] == '-' && s.length() == 2) {
				size_t pos = rule.find(s[1]);
				if (pos != string::npos) {
					ans.insert(s[1]);
					last = s[1];
					p = 0;
					if (pos + 1 < rule.length() && rule[pos + 1] == ':') {
						p = 1;
					}
				}
				else {
					break;
				}
			}
			else {
				if (p) {
					para[last] = s;
					p = 0;
				}
				else break;
			}
		}
		cout << "Case " << i << ":";
		for (auto& k : ans) {
			cout << " -" << k;
			if (para.find(k) != para.end()) {
				cout << " " << para[k];
			}
		}
		cout << endl;
	}
	return 0;
}
/*
albw:x
4
ls -a -l -a documents -b
ls
ls -w 10 -x -w 15
ls -a -b -c -d -e -l
*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/