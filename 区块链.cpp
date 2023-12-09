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
const int M = 1e6 + 5;
const int N = 5e2 + 5;
const ll mod = 998244353;
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
	//cout << x << " " << y << endl;
}

ll getine(ll a, ll p) {//a%p意义下的逆元
	ll x, y;
	Exgcd(a, p, x, y);
	x = (x % p + p) % p;
	return x;
}*/

int n, m, t;
vector<int> edge[555];
struct node{
	int sum = 0;
	int times[N] = { 0 };
	vector<int> str[N];
}block[555];
queue<pair<int, int>> que;

void update(int now, int b) {
	int l = 1, r = block[now].sum, mid, x;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (block[now].times[mid] <= b - t) x = mid, l = mid + 1;
		if (block[now].times[mid] > b - t) r = mid - 1;
	}
	int len = block[now].str[x].size();
	for (auto& i : edge[now]) {
		int id = block[i].sum;
		int size = block[i].str[id].size();
		if (size < len || (size==len && block[i].str[id][size-1] > block[now].str[x][size-1])) {
			if (block[i].times[id] < b) {
				id = ++block[i].sum;
			}
			block[i].times[id] = b;
			block[i].str[id] = block[now].str[x];
			que.push({ i,b + t });
		}
	}
}

void add(int a, int b, int c) {
	int now = block[a].sum;
	if (block[a].times[now] < b) {
		now = ++block[a].sum;
		block[a].str[now] = block[a].str[now - 1];
	}
	block[a].times[now] = b;
	block[a].str[now].push_back(c);
	que.push({ a,b + t });
}

void query(int a, int b) {
	int l = 1, r = block[a].sum, mid;
	int now = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (block[a].times[mid] < b) now = mid, l = mid + 1;
		if (block[a].times[mid] == b) {
			now = mid; break;
		}
		if (block[a].times[mid] > b) r = mid - 1;
	}
	printf("%d", block[a].str[now].size());
	for (auto& i : block[a].str[now]) {
		printf(" %d", i);
	}
	printf("\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		block[i].sum = 1;
		block[i].str[1].push_back(0);
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int k;
	cin >> t >> k;
	string temp;
	getline(cin, temp);
	for (int i = 1; i <= k; i++) {
		string s;
		getline(cin, s);
		stringstream ss;
		ss << s;
		int a[4], tot = 0;
		while (ss >> s) {
			a[++tot] = stoi(s);
		}
		if (tot == 3) {
			while (!que.empty()) {
				pair<int, int> temp = que.front();
				if (temp.second > a[2]) break;
				update(temp.first, temp.second);
				que.pop();
			}
			add(a[1], a[2], a[3]);
		}
		else {
			while (!que.empty()) {
				pair<int, int> temp = que.front();
				if (temp.second > a[2]) break;
				update(temp.first, temp.second);
				que.pop();
			}
			query(a[1], a[2]);
		}
	}
	return 0;
}
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/