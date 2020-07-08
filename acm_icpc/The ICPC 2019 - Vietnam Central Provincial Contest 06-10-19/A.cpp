#include <bits/stdc++.h>
using namespace std;

vector<string>save;

bool chk(string &s) {
	int n = s.size();
	for (int i = 1; i < n; ++i)
		if (s.substr(0, i) >= s.substr(i, n))
			return false;
	return true;
}

void dfs(string &s, int p, int n) {
	if (p == n) {
		if (chk(s)) {
			//cout << s << '\n';
			save.push_back(s);
		}
		return;
	}
	s += '0';
	dfs(s, p + 1, n);
	s.pop_back();

	s += '1';
	dfs(s, p + 1, n);
	s.pop_back();
}

void next(string &s) {
	int cnt0 = 0, cnt1 = 0, pos = -1, n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0')
			pos = i;
	}

	if (pos == 0) {
		s = "";
		return;
	}

	s[pos++] = '1';

	for (int i = 0; i < pos; ++i) {
		if (i && s[i] == '0' && s[i - 1] == '1')break;

		cnt0 += s[i] == '0';
		cnt1 += s[i] == '1';
	}

	//cout << cnt0 << ' ' << cnt1 << '\n';

	while (pos < n) {
		if (n - pos >= cnt0 + cnt1) {
			//cout << "fill " << pos << ' ' << cnt0 << ' ' << cnt1 << '\n';
			for (int i = 0; i < cnt0; ++i) s[pos++] = '0';
			for (int i = 0; i < cnt1; ++i) s[pos++] = '1';
			continue;
		}

		cnt1 = 1;
		while (n - pos < cnt0 + cnt1) {
			cnt0--;
		}
	}
}

void get_next(string &s) {
	while (1) {
		next(s);
		if (chk(s))break;
	}
}

void solve() {
	int t;
	cin >> t;

	while ( t-- ) {
		string s;
		cin >> s;

		if (s == "0") {
			cout << "1\n";
			continue;
		}
		if (s == "1") {
			cout << "\n";
			continue;
		}

		get_next(s);
		cout << s << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	solve();
	/*string s = "";
	dfs(s, 0, 15);
	save.push_back(s);
	*/

	/*int n = save.size();
	for (int i = 1; i < n; ++i) {
		s = save[i - 1];
		get_next(s);
		//cout << save[i - 1] << ' ' << s << " true :" << save[i] << ' ';
		if (s != save[i]) cout << "wrong\n";
	}
	*/

	/*s = "00000111";
	get_next(s);
	cout << s << '\n';
	*/

	return 0;
}