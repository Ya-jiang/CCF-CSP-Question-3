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

int n, ans = 0;

bool judgeNull(string s) {
	int l = s.length();
	for (int i = 0; i < l; i++) {
		if (s[i] != ' ') {
			return false;
		}
	}
	return true;
}

string deleteNull(string s) {
	int head = 0, tail = s.length() - 1;
	string res = "";
	while (head <= tail && s[head] == ' ') head++;
	while (tail >= head && s[tail] == ' ') tail--;
	for (int i = head; i <= tail; i++) res += s[i];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	string s;
	int type = 0, rest = 0;//1空行 2段落 3项目 4项目内容 5空项目
	while (getline(cin, s)) {
		if (!judgeNull(s)) break;
	}
	do {
		bool flag = judgeNull(s);
		if (flag) {
			type = 1;
			continue;
		}
		int l = s.length();
		if (l > 1 && s[0] == '*' && s[1] == ' ') {//项目
			s.erase(0, 2);
			s = deleteNull(s);
			if (type == 1 || type == 2) {
				ans++;
				rest = 0;
			}
			type = 3;
			if (judgeNull(s)) {
				ans++; rest = 0;
				type = 5;
				continue;
			}
			int pos = 0;
			l = s.length();
			while (pos < l) {
				ans++;
				while (pos < l && s[pos] == ' ') pos++;
				if (pos + n - 3 < l) {
					pos += n - 3;
					continue;
				}
				else {
					rest = n - 3 - (l - pos);
					break;
				}
			}
		}
		else if (((type == 4 || type == 5) && l > 1 && s[0] == ' ' && s[1] == ' ') || (l > 1 && type == 3 && s[0] == ' ' && s[1] == ' ')) {//项目内容
			s = deleteNull(s);
			int pos = 0;
			l = s.length();
			if (type == 5) {
				if (l > n-3) {
					rest = 0;
					pos += n-3;
				}
				else {
					rest = n-3 - l;
					type = 4;
					continue;
				}
			}
			if (rest) {
				if (l > rest - 1) {
					pos += rest - 1;
					rest = 0;
				}
				else {
					rest = rest - 1 - l;
					type = 4;
					continue;
				}
			}
			while (pos < l) {
				ans++;
				while (pos < l && s[pos] == ' ') pos++;
				if (pos + n - 3 < l) {
					pos += n - 3;
					continue;
				}
				else {
					rest = n - 3 - (l - pos);
					break;
				}
			}
			type = 4;
		}
		else {//段落
			s = deleteNull(s);
			if (type == 1 || type == 3 || type == 4 || type == 5) {
				ans++;
				rest = 0;
			}
			int pos = 0;
			l = s.length();
			if (rest) {
				if (l > rest - 1) {
					pos += rest - 1;
					rest = 0;
				}
				else {
					rest = rest - 1 - l;
					type = 2;
					continue;
				}
			}
			while (pos < l) {
				ans++;
				while (pos < l && s[pos] == ' ') pos++;
				if (pos + n < l) {
					pos += n;
					continue;
				}
				else {
					rest = n - (l - pos);
					break;
				}
			}
			type = 2;
		}
	}while (getline(cin, s));
	cout << ans;
	return 0;
}
/*
10
CSP

CSP is
a real realrealrealrealreal
	 competition.


Come   and   join   us
*/
/*
10
* CSP

*   CSP is
  * a real
	 competition.
*
  * Come!   and   join.
*Tel:
* 12345
*
*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/