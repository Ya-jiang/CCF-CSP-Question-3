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

struct node {
	int buy;
	double p, s;
	bool exis;
}sto[5005];

vector<node> stock;
set<double> num;
double ans1, ans2;
int sum;

int main() {
	ios::sync_with_stdio(false);
	string s;
	while (cin>>s) {
		if (s == "cancel") {
			int k;
			cin >> k;
			sto[k].exis = 0;
			sto[++sum].exis = 0;
		}
		else {
			int buy = 0;
			if (s == "buy") buy = 1;
			double n1;
			cin >> n1;
			double n2;
			cin >> n2;
			node temp;
			temp.buy = buy;
			temp.p = n1;
			temp.s = n2;
			sto[++sum] = temp;
			sto[sum].exis = 1;
			num.insert(n1);
		}
	}
	for (int i = 1; i <= sum; i++) {
		if(sto[i].exis)
			stock.push_back(sto[i]);
	}
	for (auto& i : num) {
		double buy = 0, sell = 0;
		for (auto& j : stock) {
			if (j.buy) {
				if (j.p >= i) buy += j.s;
			}
			else {
				if (j.p <= i) sell += j.s;
			}
		}
		buy = min(buy, sell);
		if (buy > ans2) {
			ans2 = buy;
			ans1 = i;
		}
		if (buy == ans2) {
			ans1 = max(ans1, i);
		}
	}
	printf("%.2lf %.0lf", ans1, ans2);
	return 0;
}
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/