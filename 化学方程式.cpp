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

struct node {
	int dep;
	string s;
};
stack<node> stac;

int getnum(string s, int& num) {
	if (s[num] > '9' || s[num] < '0') return 1;
	int res = 0;
	while (s[num] <= '9' && s[num] >= '0') {
		res = res * 10 + (s[num] - '0');
		num++;
	}
	return res;
}

void getss(string s, int& num) {
	int dep = 0, l = s.length();
	while (s[num] != '+' && num < l && s[num] != '=') {
		node temp;
		//cout << num << " " << s[num] << endl;
		if (s[num] == '(') {
			dep++;
			temp.dep = dep;
			temp.s = "(";
			stac.push(temp);
			num++;
		}
		if (s[num] == ')') {
			dep--;
			temp.dep = dep;
			temp.s = ")";
			stac.push(temp);
			num++;
		}
		if (s[num] <= '9' && s[num] >= '0') {
			temp.dep = dep;
			temp.s = "";
			while (s[num] <= '9' && s[num] >= '0') {
				temp.s += s[num];
				num++;
			}
			stac.push(temp);
		}
		if (s[num] >= 'A' && s[num] <= 'Z') {
			temp.dep = dep;
			if (num + 1 < l && s[num + 1] >= 'a' && s[num + 1] <= 'z') {
				temp.s = s[num] + s[num + 1];
				num += 2;
			}
			else {
				temp.s = s[num];
				num++;
			}
			stac.push(temp);
		}
	}
	//cout << "ok" << endl;
}

int trans(string s) {
	int res = 0, l = s.length();
	for (int i = 0; i < l; i++) {
		res = res * 10 + (s[i] - '0');
	}
	return res;
}

bool judge(string s) {
	map<string, int> ele;
	set<string> vis;
	int pos = 0, l = s.length();
	while (s[pos] != '=') {
		if (s[pos] == '+') {
			pos++;
			continue;
		}
		int num = getnum(s, pos);
		getss(s, pos);
		//cout << pos << " " << s[pos] << endl;
		int x = 1, y = 1;
		stack<int> k;
		while (!stac.empty()) {
			node temp = stac.top();
			stac.pop();
			int d = temp.dep;
			string ss = temp.s;
			//cout << ss << endl;
			if (ss == "(") {
				if (!k.empty()) {
					y /= k.top();
					k.pop();
				}
			}
			else if (ss == ")") {
				k.push(x);
				y *= x;
				x = 1;
			}
			else if (ss[0] >= '0' && ss[0] <= '9') {
				x = trans(ss);
				//y *= x;
			}
			else {
				vis.insert(ss);
				ele[ss] += num * x * y;
				x = 1;
			}
		}
	}
	//cout << pos;
	pos++;
	while (pos < l) {
		if (s[pos] == '+') {
			pos++;
			continue;
		}
		int num = getnum(s, pos);
		getss(s, pos);
		int x = 1, y = 1;
		stack<int> k;
		while (!stac.empty()) {
			node temp = stac.top();
			stac.pop();
			int d = temp.dep;
			string ss = temp.s;
			if (ss == "(") {
				if (!k.empty()) {
					y /= k.top();
					k.pop();
				}
			}
			else if (ss == ")") {
				k.push(x);
				y *= x;
				x = 1;
			}
			else if (ss[0] >= '0' && ss[0] <= '9') {
				x = trans(ss);
			}
			else {
				vis.insert(ss);
				ele[ss] -= num * x * y;
				x = 1;
			}
		}
	}
	set<string>::iterator it;
	for (it = vis.begin(); it != vis.end(); it++) {
		//cout << *it << endl;
		if (ele[*it]!=0) return false;
	}
	return true;
}

/*
11
H2+O2=H2O
2H2+O2=2H2O
H2+Cl2=2NaCl
H2+Cl2=2HCl
CH4+2O2=CO2+2H2O
CaCl2+2AgNO3=Ca(NO3)2+2AgCl
3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2
3Ba(OH)2+2H3PO4=Ba3(PO4)2+6H2O
4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH
Cu+As=Cs+Au
*/

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (judge(s)) cout << "Y";
		else cout << "N";
		cout << endl;
	}
	return 0;
}
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/