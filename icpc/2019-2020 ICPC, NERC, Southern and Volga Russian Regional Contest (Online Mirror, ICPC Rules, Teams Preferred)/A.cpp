#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	vector<int>mx(n), mn(n), ps(n), id(n);

	for (int i = 0; i < n; ++i)mn[i] = mx[i] = ps[i] = id[i] = i;

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		x--;

		if (id[x] == 0)continue;

		int idx = id[x];
		int idu = idx - 1;
		int u = ps[id[x] - 1];

		id[x] = idu;
		id[u] = idx;
		ps[idx] = u;
		ps[idu] = x;

		mn[x] = min(mn[x], id[x]);
		mx[x] = max(mx[x], id[x]);

		mn[u] = min(mn[u], id[u]);
		mx[u] = max(mx[u], id[u]);
	}

	for (int i = 0; i < n; ++i)
		cout << mn[i] + 1 << ' ' << mx[i] + 1 << '\n';

	return 0;
}