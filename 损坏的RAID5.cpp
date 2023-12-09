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
/*
void Exgcd(ll a, ll b, ll& x, ll& y) {
	if (!b) x = 1, y = 0;
	else Exgcd(b, a % b, y, x), y -= a / b * x;
}

int getine(int a, int p) {//a%p意义下的逆元
	ll x, y;
	Exgcd(a, p, x, y);
	x = (x % p + p) % p;
	return x;
}
*/

int n, s, l, tot = -1, datalen;
struct node {
	string data;
	bool exis;
}disk[1010];
map<char, int> num;
map<int, string> alpha;

string ope(string s, int d, int addr) {
	int p = addr * 8;
	string ss = disk[d].data, res="";
	//cout << d << " " << addr << endl;
	//cout << ss.length() << endl;
	//if (ss.length()<8) exit(0);
	//cout << ss << endl;
	//cout << p << endl;
	for (int j = p, k = 1, i=0; k <= 8; k++, j++, i++) {
		int temp = num[s[i]] ^ num[ss[j]];
		//cout <<"i: "<<i<<" "<< num[s[i]] << " " << num[ss[j]] << endl;
		res += alpha[temp];
		//cout << res << endl;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	for (char c = '0'; c <= '9'; c++) {
		num[c] = c - '0';
	}
	for (char c = 'A'; c <= 'F'; c++) {
		num[c] = c - 'A' + 10;
	}
	alpha[0] = "0", alpha[1] = "1", alpha[2] = "2", alpha[3] = "3";
	alpha[4] = "4", alpha[5] = "5", alpha[6] = "6", alpha[7] = "7";
	alpha[8] = "8", alpha[9] = "9", alpha[10] = "A", alpha[11] = "B";
	alpha[12] = "C", alpha[13] = "D", alpha[14] = "E", alpha[15] = "F";
	cin >> n >> s >> l;
	for (int i = 0; i < n; i++) {
		disk[i].exis = false;
	}
	for (int i = 0; i < l; i++) {
		int k;
		cin >> k;
		disk[k].exis = true;
		cin >> disk[k].data;
		datalen = disk[k].data.length();
	}
	/*int row = datalen / (s * 8), disknow = 0, p=n-1;
	for (int i = 0; i < row; i++) {
		int temp = n;
		while (temp) {
			if (disknow == p) {
				disknow = p;
				p--;
				if (p < 0) p = n - 1;
			}
			else {
				for (int j = i * s, k = 1; k <= s; j++, k++) {
					++tot;
					pos[tot] = make_pair(disknow, j);
				}
				disknow++;
				disknow %= n;
			}
			temp--;
		}
	}*/
	/*for (int i = 0; i < n; i++) {
		cout << disk[i].exis << endl;
		if (disk[i].exis) {
			for (int j = 0; j < datalen / 8; j++)
				cout << disk[i].blk[j] << " ";
			cout << endl;
		}
	}*/
	tot = datalen / 8 * n - 1 - (s * (datalen / 8 / s));
	//cout << tot << endl;
	int m, b;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b;
		//int d = pos[b].first, addr = pos[b].second;
		int addr = b / (n - 1) / s * s + b % s;
		int d = b / s + 1;
		int temp1 = d % (n - 1) == 0 ? d / (n - 1) : d / (n - 1) + 1;
		//cout << "temp1: " << temp1 << endl;
		temp1 %= n; temp1 = n - temp1; temp1 %= n;
		int temp2 = d % (n - 1);
		if (!temp2) temp2 = n - 1;
		for (int j = temp1 + 1, k = 1; k <= temp2; k++, j++) {
			j %= n;
			d = j;
		}
		//cout << d << " " << addr << " " << temp1 << " " << temp2 << endl;
		if (b > tot) {
			cout << "-" << endl;
			continue;
		}
		if (n - l > 1 && !disk[d].exis) {
			cout << "-" << endl;
			continue;
		}
		if (disk[d].exis) {
			int p = addr * 8;
			for (int j = p, k = 1; k <= 8; k++, j++) {
				cout << disk[d].data[j];
			}
			cout << endl;
			continue;
		}
		string ans = "00000000";
		for (int j = 0; j < n; j++) {
			if (j == d) continue;
			ans = ope(ans, j, addr);
		}
		cout << ans << endl;
	}
	return 0;
}
/*
3 2 2
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
2
2
5

2 1 2
0 000102030405060710111213141516172021222324252627
1 000102030405060710111213141516172021222324252627
2
0
1
*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/