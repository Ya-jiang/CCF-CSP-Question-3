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

int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool judge(int year) {
	if (year % 400 == 0) return 1;
	if (year % 4 == 0 && year % 100 != 0) return 1;
	return 0;
}

int getweek(int year, int month, int day) {
	int res = 0;
	for (int i = 1850; i < year; i++) {
		if (judge(i)) res += 366;
		else res += 365;
	}
	for (int i = 1; i < month; i++) res += mon[i];
	if (judge(year) && month > 2) res++;
	res += day;
	res %= 7;
	res = (res + 1) % 7;
	return res == 0 ? 7 : res;
}

int main() {
	ios::sync_with_stdio(false);
	int a, b, c, y1, y2;
	cin >> a >> b >> c >> y1 >> y2;
	for (int i = y1; i <= y2; i++) {
		int d = getweek(i, a, 1);
		int tot = mon[a];
		if (a == 2 && judge(i)) tot++;
		int k = b;
		for (int j = 1; j <= tot; j++) {
			if (d == c) k--;
			if (!k) {
				cout << i << "/";
				if (a < 10) cout << "0";
				cout << a << "/";
				if (j < 10) cout << "0";
				cout << j << endl;
				break;
			}
			d++;
			if (d > 7) d = 1;
		}
		if (k) cout << "none" << endl;
	}
	return 0;
}

/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/