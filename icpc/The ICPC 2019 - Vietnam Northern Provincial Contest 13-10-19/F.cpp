#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<long long>> save(m);
	vector<vector<int>> e(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		--u;
		--v;
		save[i] = vector<long long>({u, v, w});
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vector<vector<int>> d(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = 1e6;
		}
		for (auto j: e[i]) {
			d[i][j] = 1;
		}
		d[i][i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				d[u][v] = min(d[u][v], d[u][i] + d[i][v]);
			}
		}
	}
	const long long oo = 1e18;
	const int md = 1e9;
	vector<vector<long long>> f(n, vector<long long>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			f[i][j] = oo;
		}
	}
	for (auto i: save) {
		int u = i[0];
		int v = i[1];
		long long w = i[2];
		for (int x = 0; x < n; ++x) {
			for (int y = x + 1; y < n; ++y) {
				int delta = min(d[x][u] + 1 + d[v][y], d[x][v] + 1 + d[u][y]);
				if (delta < 1e6) {
					f[x][y] = min(f[x][y], w * delta);
				}
			}
		}
	}
	long long ans = 0;
	bool fuck = false;
	for (int x = 0; x < n; ++x) {
		for (int y = x + 1; y < n; ++y) {
			if (f[x][y] != oo) {
				ans += f[x][y];
				if (ans >= md) {
					fuck = true;
					ans %= md;
				}
			}
		}
	}
	if (!fuck) {
		cout << ans << '\n'; 
	} else {
		vector<int> digits;
		while (digits.size() < 9) {
			digits.push_back(ans % 10);
			ans /= 10;
		}
		while (!digits.empty()) {
			cout << digits.back();
			digits.pop_back();
		}
		cout << '\n';
	}
	return 0;
}