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
//#define inf INT32_MAX
//std::numeric_limits<int>::max()
//_LINE_  _TIME_  _DATE_
using namespace std;
const int M = 1000000000+1;
const int N = 5e6 + 10;
const int mod = 1e9 + 7;
const int inf = 2147483647;
const double eps = 1e-9;
int read() {
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

int m, n, p, q;
string ans="";
map<char, int> num;
map<int, string> out;
map<int, string> tos;
struct node {
	int a, b, c;
}color[2000][2000], col[2000][2000];

void modify(string s, int x, int y) {
	int l = s.length();
	string res = "";
	if (l == 4) {
		res += s[1];
		res += s[1];
		res += s[2];
		res += s[2];
		res += s[3];
		res += s[3];
	}
	else if (l == 2) {
		for (int i = 1; i <= 6; i++)
			res += s[1];
	}
	else {
		for (int i = 1; i <= 6; i++)
			res += s[i];
	}
	color[x][y].a = num[res[0]] * 16 + num[res[1]];
	color[x][y].b = num[res[2]] * 16 + num[res[3]];
	color[x][y].c = num[res[4]] * 16 + num[res[5]];
}

void cal(int x, int y, int px, int py) {
	int a = 0, b = 0, c = 0;
	for (int i = px; i <= px+q-1; i++) {
		for (int j = py; j <= py+p-1; j++) {
			a += color[i][j].a;
			b += color[i][j].b;
			c += color[i][j].c;
		}
	}
	int k = p * q;
	col[x][y].a = a/k;
	col[x][y].b = b/k;
	col[x][y].c = c/k;
}

int main() {
	ios::sync_with_stdio(false);
	for (char c = '0'; c <= '9'; c++) {
		num[c] = c - '0';
	}
	for (char c = 'a', cc = 'A'; c <= 'f'; c++, cc++) {
		num[c] = (c - 'a') + 10;
		num[cc] = (cc - 'A') + 10;
	}
	tos[0] = "30", tos[1] = "31", tos[2] = "32", tos[3] = "33";
	tos[4] = "34", tos[5] = "35", tos[6] = "36", tos[7] = "37";
	tos[8] = "38", tos[9] = "39"; 
	for (int i = 0; i <= 255; i++) {
		if (i > 99) out[i] += "\\x"+tos[i / 100];
		if (i > 9) out[i] += "\\x"+tos[(i % 100) / 10];
		out[i] += "\\x"+tos[i % 10];
	}
	cin >> m >> n >> p >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			string s;
			cin >> s;
			modify(s, i, j);
		}
	}
	int aa=0, bb=0, cc=0;
	for (int i = 1; i <= n / q; i++) {
		int temp = 0, a, b, c;
		for (int j = 1; j <= m / p; j++) {
			cal(i, j, (i - 1) * q + 1, (j - 1) * p + 1);
			a = col[i][j].a;
			b = col[i][j].b;
			c = col[i][j].c;
			if (aa == a && bb == b && cc == c) {
				temp++;
			}
			else {
				for (int k = 1; k <= temp; k++) {
					ans += "\\x20";
				}
				temp = 1;
				if (a || b || c)
					ans += "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B" + out[a] + "\\x3B" + out[b] + "\\x3B" + out[c] + "\\x6D";
				else
					ans += "\\x1B\\x5B\\x30\\x6D";
				aa = a, bb = b, cc = c;
			}
		}
		for (int k = 1; k <= temp; k++) {
			ans += "\\x20";
		}
		if (aa || bb || cc) {
			ans += "\\x1B\\x5B\\x30\\x6D";
			aa = 0, bb = 0, cc = 0;
		}
		ans += "\\x0A";
	}
	cout << ans;
	return 0;
}
/*
2 2
1 2
#111111
#0
#000000
#111
*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/