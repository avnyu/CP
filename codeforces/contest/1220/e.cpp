#include<bits/stdc++.h>
#define i64 int64_t
#define endl '\n'

using namespace std;

i64 N = 2e5 + 7;
i64 n, m, s;
i64 ans, add;
vector<vector<i64>>graph(N);
vector<i64>val(N);
vector<bool>isLoop(N), visited(N);

i64 dfs_2(i64 u, i64 p) {
	i64 res = 0;
	for (auto&v : graph[u]) {
		if (v == p)continue;
		res = max(res, dfs_2(v, u));
	}

	return res + val[u];
}

i64 dfs(i64 u, i64 p) {
	if (visited[u]) {
		//cout << "visited " << u << ' ' << p << '\n';
		return isLoop[u] = 1;
	}
	visited[u] = 1;

	for (auto&v : graph[u]) {
		if (v != p && dfs(v, u))
			isLoop[u] = isLoop[v] = 1;
	}

	for (auto&v : graph[u]) {
		if (v != p && isLoop[u] && !isLoop[v]) {
			//cout << "path to nonloop " << v << ' ' << u << ' ' << p << '\n';
			add = max(add, dfs_2(v, u));
		}
	}

	if (isLoop[u]) {
		ans += val[u];
		//cout << "val in loop " << u << ' ' << val[u] << endl;
	}

	return isLoop[u];
}

void db() {
	cout << "isLoop ";
	for (int i = 1; i <= n; ++i)cout << isLoop[i] << ' '; cout << '\n';
	cout << ans << ' ' << add << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> val[i];
	for (i64 i = 0; i < m; ++i) {
		i64 u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cin >> s;

	isLoop[s] = 1;
	dfs(s, -1);

	cout << ans + add << '\n';

	//db();

	return 0;
}