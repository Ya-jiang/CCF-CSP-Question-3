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

int n, m, q;
string ans[111];
bool vis[111][111];

void drawc(int x, int y, string s) {
	if (vis[x][y]) return;
	if (ans[x][y] == '-' || ans[x][y] == '|' || ans[x][y] == '+') return;
	ans[x][y] = s[0];
	vis[x][y] = 1;
	if (x > 0) {
		drawc(x - 1, y, s);
	}
	if (x < n-1) {
		drawc(x + 1, y, s);
	}
	if (y > 0) {
		drawc(x, y - 1, s);
	}
	if (y < m - 1) {
		drawc(x, y + 1, s);
	}
}

void drawl(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {//-
		if (y1 > y2) swap(y1, y2);
		for (int i = y1; i <= y2; i++) {
			if (ans[x1][i] == '|' || ans[x1][i] == '+') ans[x1][i] = '+';
			else ans[x1][i] = '-';
		}
	}
	else {//|
		if (x1 > x2) swap(x1, x2);
		for (int i = x1; i <= x2; i++) {
			if(ans[i][y1] == '-' || ans[i][y1] == '+') ans[i][y1] = '+';
			else ans[i][y1] = '|';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> m >> n >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i] += ".";
		}
	}
	for (int i = 1; i <= q; i++) {
		int o;
		cin >> o;
		if (o) {
			int x, y;
			string s;
			cin >> y >> x >> s;
			memset(vis, false, sizeof(vis));
			drawc(n-1-x, y, s);
		}
		else {
			int x1, x2, y1, y2;
			cin >> y1 >> x1 >> y2 >> x2;
			drawl(n-1-x1, y1, n-1-x2, y2);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/