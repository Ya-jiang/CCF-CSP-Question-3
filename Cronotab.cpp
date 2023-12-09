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

int n, sdate[6], tdate[6];
map<string, int> num;
struct node {
	int minutes[66];
	int hours[25];
	int days[33];
	int months[15];
	int weeks[8];
	string rw;
}task[25];
list<pair<string,int>> ans;

void trans(string s, bool k) {
	int pos = 0;
	int y=0, m=0, d=0, h=0, mm=0;
	for (int i = 1; i <= 4; i++, pos++) {
		y = y * 10 + s[pos] - '0';
	}
	for (int i = 1; i <= 2; i++, pos++) {
		m = m * 10 + s[pos] - '0';
	}
	for (int i = 1; i <= 2; i++, pos++) {
		d = d * 10 + s[pos] - '0';
	}
	for (int i = 1; i <= 2; i++, pos++) {
		h = h * 10 + s[pos] - '0';
	}
	for (int i = 1; i <= 2; i++, pos++) {
		mm = mm * 10 + s[pos] - '0';
	}
	if (!k) {
		sdate[1] = y;
		sdate[2] = m;
		sdate[3] = d;
		sdate[4] = h;
		sdate[5] = mm;
	}
	else {
		tdate[1] = y;
		tdate[2] = m;
		tdate[3] = d;
		tdate[4] = h;
		tdate[5] = mm;
	}
}

void ope(string s, int x) {
	int l, pos, temp;
	stringstream ss;
	ss << s;
	ss >> s;//minutes
	if (s[0] == '*') {
		for (int i = 0; i <= 59; i++) {
			task[x].minutes[i]=1;
		}
	}
	else {
		l = s.length();
		pos = 0;
		temp = 0;
		int from = -1;
		while (pos < l) {
			if (s[pos] == ',') {
				if (from != -1) {
					for (int i = from; i <= temp; i++)
						task[x].minutes[i]=1;
					from = -1;
				}
				else
					task[x].minutes[temp]=1;
				temp = 0;
			}
			else if (s[pos] == '-') {
				from = temp;
				temp = 0;
			}
			else {
				temp = temp * 10 + s[pos] - '0';
			}
			pos++;
		}
		if (from != -1) {
			for (int i = from; i <= temp; i++)
				task[x].minutes[i]=1;
			from = -1;
		}
		else
			task[x].minutes[temp]=1;
	}
	ss >> s;//hours
	if (s[0] == '*') {
		for (int i = 0; i <= 23; i++) {
			task[x].hours[i]=1;
		}
	}
	else {
		l = s.length();
		pos = 0;
		temp = 0;
		int from = -1;
		while (pos < l) {
			if (s[pos] == ',') {
				if (from != -1) {
					for (int i = from; i <= temp; i++)
						task[x].hours[i]=1;
					from = -1;
				}
				else
					task[x].hours[temp]=1;
				temp = 0;
			}
			else if (s[pos] == '-') {
				from = temp;
				temp = 0;
			}
			else {
				temp = temp * 10 + s[pos] - '0';
			}
			pos++;
		}
		if (from != -1) {
			for (int i = from; i <= temp; i++)
				task[x].hours[i]=1;
			from = -1;
		}
		else
			task[x].hours[temp]=1;
	}
	ss >> s;//days
	if (s[0] == '*') {
		for (int i = 1; i <= 31; i++) {
			task[x].days[i]=1;
		}
	}
	else {
		l = s.length();
		pos = 0;
		temp = 0;
		int from = -1;
		while (pos < l) {
			if (s[pos] == ',') {
				if (from != -1) {
					for (int i = from; i <= temp; i++)
						task[x].days[i]=1;
					from = -1;
				}
				else
					task[x].days[temp]=1;
				temp = 0;
			}
			else if (s[pos] == '-') {
				from = temp;
				temp = 0;
			}
			else {
				temp = temp * 10 + s[pos] - '0';
			}
			pos++;
		}
		if (from != -1) {
			for (int i = from; i <= temp; i++)
				task[x].days[i]=1;
			from = -1;
		}
		else
			task[x].days[temp]=1;
	}
	ss >> s;//months
	if (s[0] == '*') {
		for (int i = 1; i <= 12; i++) {
			task[x].months[i]=1;
		}
	}
	else {
		l = s.length();
		pos = 0;
		temp = 0;
		int from = -1;
		string ss = "";
		bool isnum = 1;
		while (pos < l) {
			if (s[pos] == ',') {
				if (isnum) temp = stoi(ss);
				else transform(ss.begin(), ss.end(), ss.begin(), ::tolower),temp = num[ss]; 
				if (from != -1) {
					for (int i = from; i <= temp; i++)
						task[x].months[i]=1;
					from = -1;
				}
				else
					task[x].months[temp]=1;
				temp = 0;
				ss = "";
				isnum = 1;
			}
			else if (s[pos] == '-') {
				if (isnum) temp = stoi(ss);
				else transform(ss.begin(), ss.end(), ss.begin(), ::tolower), temp = num[ss];
				from = temp;
				temp = 0;
				ss = "";
				isnum = 1;
			}
			else {
				//temp = temp * 10 + s[pos] - '0';
				if (s[pos] > '9' || s[pos] < '0') isnum = 0;
				ss += s[pos];
			}
			pos++;
		}
		if (isnum) temp = stoi(ss);
		else transform(ss.begin(), ss.end(), ss.begin(), ::tolower), temp = num[ss];
		if (from != -1) {
			for (int i = from; i <= temp; i++)
				task[x].months[i]=1;
			from = -1;
		}
		else
			task[x].months[temp]=1;
	}
	ss >> s;//weeks
	if (s[0] == '*') {
		for (int i = 0; i <= 6; i++) {
			task[x].weeks[i]=1;
		}
	}
	else {
		l = s.length();
		pos = 0;
		temp = 0;
		int from = -1;
		string ss = "";
		bool isnum = 1;
		while (pos < l) {
			if (s[pos] == ',') {
				if (isnum) temp = stoi(ss);
				else transform(ss.begin(), ss.end(), ss.begin(), ::tolower), temp = num[ss];
				if (from != -1) {
					for (int i = from; i <= temp; i++)
						task[x].weeks[i]=1;
					from = -1;
				}
				else
					task[x].weeks[temp]=1;
				temp = 0;
				ss = "";
				isnum = 1;
			}
			else if (s[pos] == '-') {
				if (isnum) temp = stoi(ss);
				else transform(ss.begin(), ss.end(), ss.begin(), ::tolower), temp = num[ss];
				from = temp;
				temp = 0;
				ss = "";
				isnum = 1;
			}
			else {
				//temp = temp * 10 + s[pos] - '0';
				if (s[pos] > '9' || s[pos] < '0') isnum = 0;
				ss += s[pos];
			}
			pos++;
		}
		if (isnum) temp = stoi(ss);
		else transform(ss.begin(), ss.end(), ss.begin(), ::tolower), temp = num[ss];
		if (from != -1) {
			for (int i = from; i <= temp; i++)
				task[x].weeks[i]=1;
			from = -1;
		}
		else
			task[x].weeks[temp]=1;
	}
	ss >> s;//rw
	task[x].rw = s;
}

void init() {
	num["jan"] = 1;
	num["feb"] = 2;
	num["mar"] = 3;
	num["apr"] = 4;
	num["may"] = 5;
	num["jun"] = 6;
	num["jul"] = 7;
	num["aug"] = 8;
	num["sep"] = 9;
	num["oct"] = 10;
	num["nov"] = 11;
	num["dec"] = 12;
	num["sun"] = 0;
	num["mon"] = 1;
	num["tue"] = 2;
	num["wed"] = 3;
	num["thu"] = 4;
	num["fri"] = 5;
	num["sat"] = 6;
}

int cal(int year, int month, int day) {
	int tot = 0, res = 4;
	for (int i = 1970; i < year; i++) {
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
			tot += 366;
		}
		else tot += 365;
	}
	for (int i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			tot += 31;
		}
		else tot += 30;
	}
	if (month > 2) {
		tot -= 2;
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) tot++;
	} 
	tot += day - 1;
	tot %= 7;
	res += tot;
	res %= 7;
	return res;
}
/*bool isLunar(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
int cal(int year, int month, int dayOfMonth)
{
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totDay = 0;
	for (int i = 1970; i <= year - 1; i++)
	{
		if (isLunar(i))
			totDay += 366;
		else
			totDay += 365;
	}
	for (int i = 1; i <= month - 1; i++)
	{
		if (isLunar(year) && i == 2)
			totDay += 29;
		else
			totDay += monthDay[i];
	}
	totDay += dayOfMonth;
	return (3 + totDay % 7) % 7;
}*/

string outdate(int year, int month, int day, int hour, int minute) {
	string res = "";
	res += to_string(year);
	if (month < 10) res += "0";
	res += to_string(month);
	if (day < 10) res += "0";
	res += to_string(day);
	if (hour < 10) res += "0";
	res += to_string(hour);
	if (minute < 10) res += "0";
	res += to_string(minute);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	init();
	string s, t;
	cin >> n >> s >> t;
	for (int i = 1; i <= n; i++) {
		memset(task[i].days, 0, sizeof(task[i].days));
		memset(task[i].hours, 0, sizeof(task[i].hours));
		memset(task[i].months, 0, sizeof(task[i].months));
		memset(task[i].minutes, 0, sizeof(task[i].minutes));
		memset(task[i].weeks, 0, sizeof(task[i].weeks));
		task[i].rw = "";
	}
	trans(s, false);
	trans(t, true);
	string ss;
	getline(cin, ss);
	for (int i = 1; i <= n; i++) {
		getline(cin, ss);
		ope(ss, i);
	}
	for (int i = 1; i <= n; i++) {
		for (int year = sdate[1]; year <= tdate[1]; year++) {
			for (int month = 1; month <= 12; month++) {
				if (task[i].months[month]) {
					for (int day = 1; day <= 31; day++) {
						bool k = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
						if (month == 2 && k && day > 29) break;
						else if (month == 2 && !k && day > 28) break;
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) break;
						if (task[i].days[day] && task[i].weeks[cal(year, month, day)]) {
							for (int hour = 0; hour <= 23; hour++) {
								if (task[i].hours[hour]) {
									for (int minute = 0; minute < 60; minute++) {
										if (task[i].minutes[minute]) {
											ss = outdate(year, month, day, hour, minute);
											if (ss >= s && ss < t) ans.push_back(make_pair(ss, i));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	ans.sort([](const pair<string, int>& a, const pair<string, int>& b) {
		if (a.first == b.first) return a.second < b.second;
		else return a.first < b.first;
		});
	for (auto& i : ans) {
		cout << i.first << " " << task[i.second].rw << endl;
	}
	return 0;
}
/*
3 202109111010 202109151011

4 201711170032 201711222352
0 7 * * 1,3-5 get_up
30 23 * * Sat,Sun go_to_bed
15 12,18 * * * have_dinner
0 0,0 * * * ???
*/
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/