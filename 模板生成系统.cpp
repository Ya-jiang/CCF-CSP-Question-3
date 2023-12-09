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
	cout << x << " " << y << endl;
}

int getine(int a, int p) {//a%p意义下的逆元
	ll x, y;
	Exgcd(a, p, x, y);
	x = (x % p + p) % p;
	return x;
}*/

int m, n;
string ans[111];
set<string> vis;
map<string, string> th;

int main() {
	ios::sync_with_stdio(false);
	cin >> m >> n;
	string s;
	getline(cin, s);
	for (int i = 1; i <= m; i++) {
		getline(cin, ans[i]);
		size_t pos = ans[i].find('{');
		while (pos != string::npos) {
			if (ans[i][pos + 1] == '{') {
				size_t pos2 = ans[i].find('}', pos+1);
				pos2 += 2;
				string temp = ans[i].substr(pos, pos2 - pos);
				vis.insert(temp);
				th[temp] = "";
				pos = ans[i].find('{', pos2);
			}
			else {
				pos = ans[i].find('{', pos + 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1;
		s1 = "{{ " + s1 + " }}";
		getline(cin, s2);
		s2.erase(s2.begin());
		s2.erase(s2.begin());
		s2.erase(s2.end() - 1);
		th[s1] = s2;
	}
	for (int j = 1; j <= m; j++) {
		for (auto& s1 : vis) {
			size_t pos = ans[j].find(s1);
			int l = s1.length();
			string s2 = th[s1];
			while (pos != string::npos) {
				ans[j].replace(pos, l, s2);
				pos = ans[j].find(s1, pos + l);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
/*
* 
11 2
<!DOCTYPE html>
<html>
<head>
<title>User {{ name }}</title>
</head>
<body>
<h1>{{ name }}</h1>
<p>Email: <a href="mailto:{{ email }}">{{ email }}</a></p>
<p>Address: {{ address }}</p>
</body>
</html>
name "David Beckham"
email "david@beckham.com"
*/
/*
<!DOCTYPE html>
<html>
<head>
<title>User David Beckham</title>
</head>
<body>
<h1>David Beckham</h1>
<p>Email: <a href="mailto:david@beckham.com">david@beckham.com</a></p>
<p>Address: </p>
</body>
</html>
*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/