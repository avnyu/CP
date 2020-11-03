#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	string a, b;

	cin >> a >> b;
	n = a.size(), m = b.size();

	set<string>s;

	for (int i = 0; i < n; ++i)
		for (int j = 1; j < 15 && i + j <= n; ++j) {
			s.insert(a.substr(i, j));
		}

	for (int i = 0; i < m; ++i)
		for (int j = 1; j < 15 && i + j <= m; ++j)
			s.insert(b.substr(i, j));

	queue<string>q;
	q.push(string("0"));
	q.push(string("1"));

	while (1) {
		string t = q.front();
		//cout << t << '\n';
		q.pop();

		if (s.find(t) == s.end()) {
			cout << t << '\n';
			return 0;
		}

		q.push(t + "0");
		q.push(t + "1");
	}

	return 0;
}