#include<bits/stdc++.h>
#include<fstream>
#define ll long long

using namespace std;

string solve(string &s, string &t) {
	int n = int(s.size()), m = int(t.size());
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>>trace(n + 1, vector<int>(m + 1, -1));
	vector<vector<int>>used(n + 1, vector<int>(m + 1, 0));

	int mx = -1, pi = -1, pj = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			if (dp[i][j] > dp[i + 1][j]) {
				dp[i + 1][j] = dp[i][j];
				trace[i + 1][j] = j;
				used[i + 1][j] = 0;
			}

			if (dp[i][j] + 1 > dp[i + 1][j + (s[i] == t[j])]) {
				dp[i + 1][j + (s[i] == t[j])] = dp[i][j] + 1;
				trace[i + 1][j + (s[i] == t[j])] = j;
				used[i + 1][j + (s[i] == t[j])] = 1;
			}

			if (dp[i + 1][j] > mx) {
				mx = dp[i + 1][j];
				pi = i + 1;
				pj = j;
			}
		}
	}

	stack<char>ans;
	for (int i = pi; i; --i) {
		if (used[i][pj])ans.push(s[i - 1]);
		pj = trace[i][pj];
		if (pj == -1)break;
	}
	string res = "";

	while (!ans.empty()) {
		res.push_back(ans.top());
		ans.pop();
	}

	return res;
}

bool isSub(string &a, string &b) {
	int n = a.size(), m = b.size();
	int j = 0;

	for (int i = 0; i < n && j < m; ++i)
		if (a[i] == b[j])j++;

	return j == m;
}

void test() {
	for (int i = 0; i < 1; ++i) {
		ifstream fin("testcase/DelStr/in/input" + to_string(i + 1) + ".txt");
		ifstream fout("testcase/DelStr/out/output" + to_string(i + 1) + ".txt");

		string s, t, res, ans;
		fin >> s >> t;

		res = solve(s, t);
		fout >> ans;

		cout << "Testcase " << i + 1 << "\n";
		cout << "is T S sub " << isSub(s, t) << '\n';

		cout << (res == ans ? "True\n" : "False\n");
		cout << res.size() << ' ' << ans.size() << '\n';
		cout << isSub(res, t) << ' ' << isSub(ans, t) << '\n';
		cout << isSub(s, res) << ' ' << isSub(s, ans) << '\n';

		//cout << s << '\n';
		//cout << t << '\n';
		//cout << res << '\n';
		//cout << ans << '\n';

		fin.close();
		fout.close();
	}
}

void test_2() {
	string s, t;
	cin >> s >> t;

	vector<int>cnt(128, -1);

	int mn = 1e9, ps = -1;
	for (auto&i : t)cnt[i] = 0;
	for (auto&i : s)if (cnt[i] > -1)cnt[i]++;
	for (int i = 0; i < 128; ++i) if (cnt[i] > -1 && mn > cnt[i]) {mn = cnt[i]; ps = i;}
	for (auto&i : s)if (i != ps)cout << i;
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	test_2();

	return 0;
}