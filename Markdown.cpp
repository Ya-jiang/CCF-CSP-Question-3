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

string ans = "";

bool iskong(string s) {
	int l = s.length(), pos = 0;
	while (pos < l) if (s[pos] != ' ' && s[pos]!='\n') return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	string s;
	int type = 0;
	while (getline(cin, s)) {
		if (iskong(s)) {
			if (type == 2) {
				ans += "</ul>\n";
			}
			if (type == 3) {
				ans += "</p>\n";
			}
			type = 0;
			continue;
		}
		else if (s[0] == '#') {//type=1
			if (type == 2) {
				ans += "</ul>\n";
			}
			if (type == 3) {
				int l = ans.length();
				ans.erase(ans.begin() + l - 1);
				ans += "</p>\n";
			}
			int l, pos = 0, degree=0;
			while (s[pos] == '#' || s[pos] == ' ') {
				if (s[pos] == '#') {
					degree++;
				}
				pos++;
			}
			ans += "<h" + to_string(degree) + ">";
			size_t isem = s.find('_');
			while (isem != string::npos) {
				s.replace(isem, 1, "<em>");
				size_t isem2 = s.find('_',isem);
				s.replace(isem2, 1, "</em>");
				isem = s.find('_',isem2); 
			}
			l = s.length();
			while (pos < l) {
				if (s[pos] == '[') {
					pos++;
					int pos2 = pos;
					while (s[pos2] != ']') {
						pos2++;
					}
					string a = s.substr(pos, pos2 - pos);
					pos = pos2 + 2;
					pos2 += 2;
					while (s[pos2] != ')') {
						pos2++;
					}
					string temp = s.substr(pos, pos2 - pos);
					ans += "<a href=\"" + temp + "\">" + a + "</a>";
					pos = pos2;
				}
				else {
					ans += s[pos];
				}
				pos++;
			}
			ans +=  "</h" + to_string(degree) + ">"+"\n";
			type = 1;
		}
		else if (s[0] == '*') {//type==2
			int l, pos = 0;
			if (type == 3) {
				int l = ans.length();
				ans.erase(ans.begin() + l - 1);
				ans += "</p>\n";
			}
			if (type != 2) {
				ans += "<ul>\n";
			}
			while (s[pos] == '*' || s[pos] == ' ') pos++;
			size_t isem = s.find('_');
			while (isem != string::npos) {
				s.replace(isem, 1, "<em>");
				size_t isem2 = s.find('_', isem);
				s.replace(isem2, 1, "</em>");
				isem = s.find('_', isem2);
			}
			l = s.length();
			ans += "<li>";
			while (pos < l) {
				if (s[pos] == '[') {
					pos++;
					int pos2 = pos;
					while (s[pos2] != ']') {
						pos2++;
					}
					string a = s.substr(pos, pos2 - pos);
					pos = pos2 + 2;
					pos2 += 2;
					while (s[pos2] != ')') {
						pos2++;
					}
					string temp = s.substr(pos, pos2 - pos);
					ans += "<a href=\"" + temp + "\">" + a + "</a>";
					pos = pos2;
				}
				else {
					ans += s[pos];
				}
				pos++;
			}
			ans += "</li>\n";
			type = 2;
		}
		else {//type==3
			int l, pos = 0;
			if (type == 2) {
				ans += "</ul>\n";
			}
			if (type != 3) {
				ans += "<p>";
			}
			else ans += "\n";
			size_t isem = s.find('_');
			while (isem != string::npos) {
				s.replace(isem, 1, "<em>");
				size_t isem2 = s.find('_', isem);
				s.replace(isem2, 1, "</em>");
				isem = s.find('_', isem2);
			}
			l = s.length();
			while (pos < l) {
				if (s[pos] == '[') {
					pos++;
					int pos2 = pos;
					while (s[pos2] != ']') {
						pos2++;
					}
					string a = s.substr(pos, pos2 - pos);
					pos = pos2 + 2;
					pos2 += 2;
					while (s[pos2] != ')') {
						pos2++;
					}
					string temp = s.substr(pos, pos2 - pos);
					ans += "<a href=\"" + temp + "\">" + a + "</a>";
					pos = pos2;
				}
				else {
					ans += s[pos];
				}
				pos++;
			}
			type = 3;
		}
	}
	if (type == 2) {
		ans += "</ul>";
	}
	if (type == 3) {
		ans += "</p>";
	}
	cout << ans;
	return 0;
}
/*
#     _He  llo_
######   aaa[Te_  xt_](_Lin_  k)bbb


H_ello, w_
[o](rld)!

*   aaa[Text](Link)bbb
*     _123aa_a[Text](Link)_bbb_666

*  _123aa_a[T_ex_t](_Link_)_bbb_666

# Heading

## Sub-heading

Paragraphs are separated

by a blank line.

text attributes _italic_.

Bullet list:

* apples
* oranges
* pears

bbbhj
llll

*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/