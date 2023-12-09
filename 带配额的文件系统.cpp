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

int tot = 0;

struct node {
	int judge;		//是否是普通文件
	ll LDd, LRd;	//配额
	ll sizeD, sizeR;//总大小
	ll sizeF;		//普通文件大小
	map<string, int> child;//孩子文件编号
	int fa;
}file[N];

vector<pair<string, int>> modify;

string getpath(string &x, int &num) {
	string res = "";
	int l = x.size(), i;
	for (i = num;x[i] != '/' && i < l; i++) {
		res += x[i];
	}
	num = i + 1;
	return res;
}

void rollback() {
	int size = modify.size();
	for (int i = 0; i < size; i++) {
		int k = modify[i].second;
		string s = modify[i].first;
		file[k].child.erase(file[k].child.find(s));
	}
}

bool create(string s, ll x) {
	modify.clear();
	int pre = tot;
	int now = 0, pos = 1, l = s.size();
	while (pos < l) {
		string path = getpath(s, pos);
		if (pos < l && file[now].child[path] && file[file[now].child[path]].judge) {
			tot = pre;
			rollback();
			return false;
		}
		int num, exi=0;
		if (file[now].child[path]) {
			num = file[now].child[path];
			exi = 1;
		}
		else {
			num = ++tot;
			file[tot].judge = 0;
			file[tot].fa = now;
			file[now].child[path] = tot;
			file[tot].LDd = 0;
			file[tot].LRd = 0;
			modify.push_back(make_pair(path, now));
		}
		if (pos < l) now = num;
		if (pos >= l) {
			ll size;
			if (exi) {
				if (!file[num].judge) {
					tot = pre;
					rollback();
					return false;
				}
				size = x - file[num].sizeF;
			}
			else size = x;
			if (file[now].LDd && file[now].sizeD + size > file[now].LDd) {
				tot = pre;
				rollback();
				return false;
			}
			file[num].judge = 1;
			file[num].sizeF = x;
			file[num].sizeR = x;
			for (int i = now; i != -1; i = file[i].fa) {
				if (file[i].LRd && file[i].sizeR + size > file[i].LRd) {
					tot = pre;
					rollback();
					return false;
				}
			}
			for (int i = now; i != -1; i = file[i].fa) {
				file[i].sizeR += size;
			}
			file[now].sizeD += size;
		}
	}
	return true;
}

void remove(string s) {
	int now = 0, pos = 1;
	int l = s.size();
	while (pos < l) {
		string path = getpath(s, pos);
		if (!file[now].child[path]) {
			return;
		}
		else {
			int num = file[now].child[path];
			if (file[num].judge) {
				if (pos < l) return;
				else {//删除文件
					ll size = file[num].sizeR;
					file[now].child.erase(file[now].child.find(path));
					file[now].sizeD -= size;
					for (int i = now; i != -1; i = file[i].fa) {
						file[i].sizeR -= size;
					}
				}
			}
			else {
				if (pos < l) {
					now = num;
				}
				else {//删除目录
					ll size = file[num].sizeR;
					file[now].child.erase(file[now].child.find(path));
					for (int i = now; i != -1; i = file[i].fa) {
						file[i].sizeR -= size;
					}
				}
			}
		}
	}
}

bool quota(string s, ll x1, ll x2) {
	if (s.size() == 1) {
		if ((x1 && x1 < file[0].sizeD) || (x2 && x2 < file[0].sizeR)) {
			return false;
		}
		file[0].LDd = x1;
		file[0].LRd = x2;
		return true;
	}
	int now = 0, l = s.size(), pos = 1;
	while (pos < l) {
		string path = getpath(s, pos);
		if (!file[now].child[path]) {
			return false;
		}
		int num = file[now].child[path];
		now = num;
		if (file[num].judge) {
			return false;
		}
		if (pos >= l) {
			if ((x1 && x1 < file[num].sizeD) || (x2 && x2 < file[num].sizeR)) {
				return false;
			}
			file[num].LDd = x1;
			file[num].LRd = x2;
			return true;
		}
		
	}
	//return true;
}

int main() {
	int n;
	cin >> n;
	//if (n > 100) exit(0);
	file[0].fa = -1;
	file[0].LDd = 0;
	file[0].LRd = 0;
	//file[0].sizeD = 0;
	//file[0].sizeR = 0;
	file[0].judge = 0;
	while (n--) {
		char c;
		cin >> c;
		string s;
		ll x1, x2;
		bool ans = true;
		if (c == 'C') {
			cin >> s >> x1;
			ans = create(s, x1);
		}
		else if (c == 'R') {
			cin >> s;
			remove(s);
		}
		else if (c == 'Q') {
			cin >> s >> x1 >> x2;
			ans = quota(s, x1, x2);
		}
		if (ans) std::cout << "Y" <<'\n';
		else std::cout << "N" << '\n';
	}
	return 0;
}
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/