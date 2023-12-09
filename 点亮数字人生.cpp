
#include<bits/stdc++.h>
using namespace std;
//Nmax=500, kmax=5, Smax=10000, Qmax=5
int head[510], tot, in[510], Q, m, n;
bool sr[10005][2505], ans[510][10005];
string func[510];
vector<bool> input[510];
vector<int> ini[510];
vector<int> que;
struct node {
	int u, v, nex;
}e[5010];

void add(int f, int t) {
	tot++;
	e[tot].u = f;
	e[tot].v = t;
	e[tot].nex = head[f];
	head[f] = tot;
}

bool ope(int x) {
	if (func[x] == "NOT") {
		return !input[x][0];
	}
	int sum = input[x].size();
	//cout << "now: " << x << " size: " << sum << endl;
	bool res = input[x][0];
	if (func[x] == "AND") {
		for (int i = 1; i < sum; i++) {
			res &= input[x][i];
		}
		return res;
	}
	if (func[x] == "OR") {
		for (int i = 1; i < sum; i++) {
			res |= input[x][i];
		}
		return res;
	}
	if (func[x] == "XOR") {
		for (int i = 1; i < sum; i++) {
			res ^= input[x][i];
		}
		return res;
	}
	if (func[x] == "NAND") {
		for (int i = 1; i < sum; i++) {
			res &= input[x][i];
		}
		return !res;
	}
	if (func[x] == "NOR") {
		for (int i = 1; i < sum; i++) {
			res |= input[x][i];
		}
		return !res;
	}
}

int getnum(string s) {
	int res = 0, l = s.length();
	for (int i = 1; i < l; i++) {
		res = res * 10 + (s[i] - '0');
	}
	return res;
}

int read() {
	int res = 0, k = 1;
	char c = getchar();
	while ((c < '0' || c>'9') && c != '-') c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') res = (res << 3) + (res << 1) + c - '0', c = getchar();
	return res * k;
}

int main(){
	Q = read();
	while (Q--) {
		m = read(), n = read();
		tot = 0;
		memset(head, 0, sizeof(head));
		memset(in, 0, sizeof(in));
		//memset(ans, false, sizeof(ans));
		//ini->clear();
		for (int i = 1; i <= n; i++) ini[i].clear();
		que.clear();
		for (int i = 1; i <= n; i++) {
			cin >> func[i];
			int k = read();
			string s;
			for (int j = 1; j <= k; j++) {
				cin >> s;
				int num = getnum(s);
				if (s[0] == 'I') {
					ini[i].push_back(num);
				}
				else {
					add(num, i);
					in[i]++;
				}
			}
		}
		int s = read();
		for (int i = 1; i <= s; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> sr[i][j];
			}
		}
		queue<int> temp;
		for (int i = 1; i <= n; i++) {
			if (!in[i]) temp.push(i);
		}
		while (!temp.empty()) {
			int k = temp.front();
			temp.pop();
			que.push_back(k);
			for (int i = head[k]; i; i = e[i].nex) {
				int t = e[i].v;
				in[t]--;
				if (!in[t]) {
					temp.push(t);
				}
			}
		}
		if (que.size() < n) {
			for (int i = 1; i <= s; i++) {
				int k = read(), x;
				for (int j = 1; j <= k; j++)
					x = read();
			}
			cout << "LOOP";
		}
		else {

			for (int i = 1; i <= s; i++) {
				for (int j = 1; j <= n; j++)
					input[j].clear();
				//input->clear();
				for (int j = 0; j < n; j++) {
					int now = que[j];
					//cout << "now: " << now << endl;
					//input[now].clear();
					for (auto& k : ini[now]) {
						input[now].push_back(sr[i][k]);
						//cout << sr[i][k] << " ";
					}
					//cout << endl;
					bool a = ope(now);
					ans[now][i] = a;
					//cout <<"now: "<< now <<" ans: "<<a << endl;
					for (int k = head[now]; k; k = e[k].nex) {
						int t = e[k].v;
						input[t].push_back(a);
					}
				}
			}
			for (int i = 1; i <= s; i++) {
				int k = read(), x;
				for (int j = 1; j <= k; j++) {
					x = read();
					cout << ans[x][i];
					if (j != k) cout << " ";
				}
				if (i != s)
					cout << endl;
			}
		}
		if (Q) cout << endl;
	}
	return 0;
}





