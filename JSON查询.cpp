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

int n, m, tot=0;
string s="", ss;

struct node {
	map<string, string> ans1;
	map<string, string> type;
	map<string, int> child;
	string key;
}json[200];

string getstring(int& pos) {
	string res = "";
	pos++;
	while (s[pos] != '\"') {
		if (s[pos] == '\\') {
			res += s[pos+1];
			pos+=2;
		}
		else {
			res += s[pos];
			pos++;
		}
	}
	pos++;
	return res;
}

void handle() {
	string key = "?-?";
	int l = s.length(), pos = 0, now = 0;
	stack<string> kv;
	stack<int> layer;
	bool iskey = 0;
	while (pos < l) {
		if (s[pos] == ' ') {
			pos++;
		}
		else if (s[pos] == '{') {
			tot++;
			json[now].type[key] = "OBJECT";
			json[now].child[key] = tot;
			iskey = 0;
			layer.push(now);
			now = tot;
			pos++;
		}
		else if (s[pos] == '\"') {
			string temp = getstring(pos);
			if (iskey) {
				json[now].ans1[key] = temp;
				json[now].type[key] = "STRING";
				iskey = 0;
			}
			else {
				kv.push(temp);
				iskey = 1;
			}
		}
		else if (s[pos] == ':') {
			if (!kv.empty()) {
				key = kv.top();
				kv.pop();
			}
			iskey = 1;
			pos++;
		}
		else if (s[pos] == ',') {
			pos++;
		}
		else if (s[pos] == '}') {
			now = layer.top();
			layer.pop();
			pos++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	getline(cin, ss);
	for (int i = 1; i <= n; i++) {
		getline(cin, ss);
		s += ss;
	}
	handle();
	for (int i = 1; i <= m; i++) {
		cin >> ss;
		int l = ss.length(), pos = 0, now = 1;
		bool exis = 1;
		string temp = "";
		while (pos < l && exis) {
			if (ss[pos] == '.') {
				if (json[now].child.find(temp) != json[now].child.end()) {
					now = json[now].child[temp];
					temp = "";
				}
				else {
					exis = 0; break;
				}
			}
			else {
				temp += ss[pos];
			}
			pos++;
		}
		if (exis) {
			if (json[now].type.find(temp) != json[now].type.end()) {
				cout << json[now].type[temp];
				if (json[now].type[temp][0] == 'S') cout << " " << json[now].ans1[temp];
				cout << endl;
			}
			else {
				cout << "NOTEXIST" << endl;
			}
		}
		else {
			cout << "NOTEXIST" << endl;
		}
	}
	return 0;
}

/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/