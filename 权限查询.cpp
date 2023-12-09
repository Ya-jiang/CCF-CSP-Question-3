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

int p, r, u;
map<string, int> quanxian;
map<string, int> idu;
map<string, int> idr;

struct node {
	string name;
	int tot = 0;
	map<string, int> qx;
	set<string> rol;
}role[111], user[111];

int main() {
	ios::sync_with_stdio(false);
	cin >> p;
	for (int i = 1; i <= p; i++) {
		string s;
		cin >> s;
		size_t pos = s.find(':');
		if (pos != string::npos) {
			string ss = s.substr(pos + 1, s.length() - pos);
			int d = stoi(ss);
			string qx = s.substr(0, pos);
			if (quanxian.find(qx) == quanxian.end())
				quanxian[qx] = d;
			else quanxian[qx] = max(d, quanxian[qx]);
		}
		else {
			quanxian[s] = -1;
		}
	}
	cin >> r;
	for (int i = 1; i <= r; i++) {
		cin >> role[i].name;
		cin >> role[i].tot;
		idr[role[i].name] = i;
		for (int j = 1; j <= role[i].tot; j++) {
			string s;
			cin >> s;
			size_t pos = s.find(':');
			if (pos != string::npos) {
				string ss = s.substr(pos + 1, s.length() - pos);
				string qx = s.substr(0, pos);
				int d = stoi(ss);
				if (role[i].qx.find(qx) == role[i].qx.end())
					role[i].qx[qx] = d;
				else role[i].qx[qx] = max(role[i].qx[qx], d);
			}
			else {
				role[i].qx[s] = -1;
			}
		}
	}
	cin >> u;
	for (int i = 1; i <= u; i++) {
		cin >> user[i].name;
		cin >> user[i].tot;
		idu[user[i].name] = i;
		for (int j = 1; j <= user[i].tot; j++) {
			string s;
			cin >> s;
			user[i].rol.insert(s);
		}
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		string s, name, qx;
		int degree=-1;
		cin >> name;
		cin >> s;
		size_t pos = s.find(':');
		if (pos != string::npos) {
			string ss = s.substr(pos + 1, s.length() - pos);
			qx = s.substr(0, pos);
			degree = stoi(ss);
		}
		else {
			qx = s;
		}
		if (idu.find(name) == idu.end() || quanxian.find(qx) == quanxian.end()) {
			cout << "false" << endl;
			continue;
		}
		int now = idu[name];
		if (degree == -1) {
			if (quanxian[qx] == -1) {
				bool flag = 0;
				for (auto& k : user[now].rol) {
					int id = idr[k];
					if (role[id].qx.find(qx) != role[id].qx.end()) {
						flag = 1; break;
					}
				}
				if(!flag) cout << "false" << endl;
				else cout << "true" << endl;
			}
			else {
				int ans = -1;
				for (auto& k : user[now].rol) {
					int id = idr[k];
					if (role[id].qx.find(qx) != role[id].qx.end())
						ans = max(ans, role[id].qx[qx]);
				}
				if (ans != -1) cout << ans << endl;
				else cout << "false" << endl;
			}
		}
		else {
			bool flag = 0;
			for (auto& k : user[now].rol) {
				int id = idr[k];
				if (role[id].qx.find(qx) != role[id].qx.end())
				{
					if (degree <= role[id].qx[qx]) {
						flag = 1; break;
					}
				}
			}
			if(flag) cout << "true" << endl;
			else cout << "false" << endl;
		}
	}
	return 0;
}
/*
3
crm:2
git:3
game
4
hr 1 crm:2
it 3 crm:1 git:1 game
dev 2 git:3 game
qa 1 git:2
3
alice 1 hr
bob 2 it qa
charlie 1 dev
9
alice game
alice crm:2
alice git:0
bob git
bob poweroff
charlie game
charlie crm
charlie git:3
malice game
*/

/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/