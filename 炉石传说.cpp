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
struct node {
	int tot = 0, servant[10];
	int blood[1111], attack[1111];
}player[3];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	string s;
	int now = 0, winner = -1;
	player[0].blood[0] = player[1].blood[0] = 30;
	player[0].servant[0] = player[1].servant[0] = 0;
	player[0].attack[0] = player[1].attack[0] = 0;
	while (n--) {
		cin >> s;
		if (s == "summon") {
			int pos, blood, attack;
			cin >> pos >> attack >> blood;
			int t = ++player[now].tot;
			if (player[now].servant[pos]) {
				int temp = pos + 1;
				while (player[now].servant[temp]) temp++;
				while (temp > pos) {
					player[now].servant[temp] = player[now].servant[temp - 1];
					temp--;
				}
			}
			player[now].servant[pos] = t;
			player[now].blood[t] = blood;
			player[now].attack[t] = attack;
		}
		else if (s == "attack") {
			int att, def;
			cin >> att >> def;
			int enemy = now ^ 1;
			int attid = player[now].servant[att], defid = player[enemy].servant[def];
			player[now].blood[attid] -= player[enemy].attack[defid];
			player[enemy].blood[defid] -= player[now].attack[attid];
			if (player[now].blood[attid]<=0) {
				player[now].servant[att] = 0;
				player[now].blood[attid] = 0;
				player[now].attack[attid] = 0;
				int pos = att + 1;
				while (player[now].servant[pos]) {
					player[now].servant[pos - 1] = player[now].servant[pos];
					player[now].servant[pos] = 0;
					pos++;
				}
			}
			if (player[enemy].blood[defid]<=0) {
				if (!def) {
					winner = now;
				}
				else {
					player[enemy].servant[def] = 0;
					player[enemy].blood[defid] = 0;
					player[enemy].attack[defid] = 0;
					int pos = def + 1;
					while (player[enemy].servant[pos]) {
						player[enemy].servant[pos - 1] = player[enemy].servant[pos];
						player[enemy].servant[pos] = 0;
						pos++;
					}
				}
			}
		}
		else if (s == "end") {
			now ^= 1;
		}
	}
	if (winner != -1) {
		if (winner) cout << -1 << endl;
		else cout << 1 << endl;
	}
	else cout << 0 << endl;
	cout << player[0].blood[0] << endl;
	vector<int> ans;
	int sum = 0;
	for (int i = 1; i <= 7; i++) {
		if (player[0].servant[i]) {
			sum++;
			ans.push_back(player[0].blood[player[0].servant[i]]);
		}
	}
	cout << sum;
	for (auto& i : ans) {
		cout << " " << i;
	}
	cout << endl;
	cout << player[1].blood[0] << endl;
	ans.clear();
	sum = 0;
	for (int i = 1; i <= 7; i++) {
		if (player[1].servant[i]) {
			sum++;
			ans.push_back(player[1].blood[player[1].servant[i]]);
		}
	}
	cout << sum;
	for (auto& i : ans) {
		cout << " " << i;
	}
	return 0;
}
/*
8
summon 1 3 6
summon 2 4 2
end
summon 1 4 5
summon 1 2 1
attack 1 2
end
attack 1 1
			*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/