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
const int N = 1e3 + 5;
const ll mod = 1e9 + 7;
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

int n, S, P, T, tot = -1;
double dt;
double vk[N], uk[N], a[N], b[N], c[N], d[N];
int times[N];
struct node {
	int s, t, D;
	double w;
};
vector<node> c_t[2*N];
double Ik[2005][1005];
int r[2005];

static unsigned long nex = 1;
/* RAND_MAX assumed to be 32767 */
int myrand(void) {
	nex = nex * 1103515245 + 12345;
	return((unsigned)(nex / 65536) % 32768);
}

int main() {
	//ios::sync_with_stdio(false);
	scanf("%d%d%d%d", &n, &S, &P, &T);
	scanf("%lf", &dt);
	int temp = 0;
	while (temp < n) {
		int rn;
		scanf("%d", &rn);
		double v, u, aa, bb, cc, dd;
		scanf("%lf%lf%lf%lf%lf%lf", &v, &u, &aa, &bb, &cc, &dd);
		for (int i = 1; i <= rn; i++) {
			tot++;
			vk[tot] = v;
			uk[tot] = u;
			a[tot] = aa;
			b[tot] = bb;
			c[tot] = cc;
			d[tot] = dd;
			times[tot] = 0;
		}
		temp += rn;
		if (temp == n) break;
	}
	for (int i = 1; i <= P; i++) {
		tot++;
		scanf("%d", &r[tot]);
	}
	int modd = 0;
	for (int i = 1; i <= S; i++) {
		int s, t, D;
		double w;
		scanf("%d%d%lf%d", &s, &t, &w, &D);
		node temp;
		temp.s = s; temp.t = t; temp.w = w; temp.D = D;
		modd = max(modd, D);
		c_t[s].push_back(temp);
	}
	modd++;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < n; i++) {
			double temp = Ik[i][t%modd];
			Ik[i][t % modd] = 0;
			double v = vk[i], u = uk[i];
			vk[i] = v + dt * (0.04 * v * v + 5.00 * v + 140.00 - u) + temp;
			uk[i] = u + dt * a[i] * (b[i] * v - u);
			if (vk[i] >= 30.00) {
				times[i]++;
				vk[i] = c[i];
				uk[i] += d[i];
				int sum = c_t[i].size();
				for (int j = 0; j < sum; j++) {
					node k = c_t[i][j];
					Ik[k.t][(t + k.D) % modd] += k.w;
				}
			}
		}
		for (int i = n; i < n + P; i++) {
			if (myrand() < r[i]) {
				int sum = c_t[i].size();
				for (int j = 0; j < sum; j++) {
					node k = c_t[i][j];
					Ik[k.t][(t + k.D) % modd] += k.w;
				}
			}
		}
	}
	double maxv = -1e10, minv = 1e10;
	int maxt = 0, mint = 10000;
	for (int i = 0; i < n; i++) {
		maxv = max(vk[i], maxv);
		minv = min(vk[i], minv);
		maxt = max(times[i], maxt);
		mint = min(times[i], mint);
	}
	printf("%.3lf %.3lf\n%d %d", minv, maxv, mint, maxt);
	return 0;
}
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/