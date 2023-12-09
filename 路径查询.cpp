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

int n;
string now;

void ope(string s) {
	if (s.empty()) {
		cout << now << endl; return;
	}
	string ans = "";
	if (s[0] != '/') s = now + "/" + s;
	int l = s.length(), pos = 0;
	while (s[l - 1] == '/' && l > 1) s.erase(s.begin() + l - 1), l--;
	if(s[l-1]=='.' && s[l-2]=='/') s.erase(s.begin() + l - 1), l--;
	while (s[l - 1] == '/' && l > 1) s.erase(s.begin() + l - 1), l--;
	size_t p = s.find('.');
	while (p != string::npos) {
		if (s[p-1]=='/' && (p==s.length()-1 || s[p+1]=='/')) {
			s.erase(s.begin() + p);
			p = s.find('.', p);
		}
		else p = s.find('.', p + 1);
	}
	p = s.find('/');
	while (p != string::npos) {
		size_t temp = p + 1;
		while (temp < s.length() && s[temp] == '/') {
			s.erase(s.begin() + temp);
		}
		p = s.find('/', temp);
	}
	l = s.length();
	while (pos < l) {
		if (s[pos] == '.' && s[pos-1]=='/' && s[pos+1]=='.' && (pos==l-2 || s[pos+2]=='/')) {
			int k = ans.length() - 1;
			if (k > 0 && ans[k] == '/') ans.erase(ans.begin() + k), k--;
			while (k > 0 && ans[k]!='/') {
				ans.erase(ans.begin() + k);
				k--;
			}
			pos += 3;
		}
		else {
			ans += s[pos];
			pos++;
		}
	}
	l = ans.length() - 1;
	while(ans[l]=='/' && l>1) ans.erase(ans.begin() + l), l--;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	getline(cin, now);
	getline(cin, now);
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		ope(s);
	}
	return 0;
}
/*
12
/d2/d3
/d2/d4/f1
../d4/f1
/d1/./f1
/d1///f1
/d1/
//////
/d1/../../././../d2
../../../../../
.././.././/.//.//.///../..
d4///./d5/..//..//../d6
./d4///./.d5/...//.//d6/./././
./d4///./d5/..//../..1.1.2./d6/../.
*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/