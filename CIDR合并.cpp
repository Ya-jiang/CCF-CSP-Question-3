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
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
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

int n;
struct node {
	int x[5];
	int len;
	string bit;
};
list<node> vec;

node toIp(string s) {//转化为32位二进制ip地址
	node ipadress;
	string ipa;
	ipadress.bit = "-";
	ipadress.len = -1;
	int tot = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size() || !isdigit(s[i])) {
			int k = stoi(ipa);
			int d = 128;
			ipadress.x[++tot] = k;
			while (d > 0) {
				if (k / d) {
					ipadress.bit += "1";
					k -= d;
				}
				else	ipadress.bit += "0";
				d /= 2;
			}
			if (s[i] == '/') {
				ipadress.len = stoi(s.substr(i + 1));
				break;
			}
			ipa = "";
		}
		else	ipa += s[i];
	}
	if (ipadress.len == -1)	ipadress.len = ipadress.bit.size()-1;//省略长度型
	while (ipadress.bit.size() < 33) {//省略后缀型
		ipadress.bit += "0";
	}
	while(tot<4) ipadress.x[++tot] = 0;
	return ipadress;
}

bool judge(node& a,node& b) {
	int l1 = a.len, l2 = b.len;
	if (l1 > l2) return false;
	for (int i = 1; i <= l1; i++) {
		if (a.bit[i]!= b.bit[i]) return false;
	}
	return true;
}

bool judge2(node& a, node& b) {
	if (a.len != b.len)	return false;
	for (int i = 1; i <= a.len - 1; i++) {
		if (a.bit[i] != b.bit[i])	return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		vec.push_back(toIp(s));
	}
	vec.sort([](const node& a, const node& b) {
		if (a.bit == b.bit)	return a.len < b.len;
		return a.bit < b.bit;
		});
	auto ii = vec.begin(), jj = vec.begin();
	for (++jj; jj != vec.end();) {
		if (judge(*ii, *jj)) {
			jj = vec.erase(jj);
		}
		else {
			ii++;
			jj++;
		}
	}
	ii = vec.begin(), jj = vec.begin();
	for (++jj; jj != vec.end();) {
		if (judge2(*ii, *jj)) {
			jj = vec.erase(jj);
			(*ii).len--;
			if (ii != vec.begin()) {
				ii--;
				jj--;
			}
		}
		else {
			ii++;
			jj++;
		}
	}
	for (auto& i : vec) {
		printf("%d.%d.%d.%d/%d\n", i.x[1], i.x[2], i.x[3], i.x[4], i.len);
	}
	return 0;
}
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/