#include<bits/stdc++.h>
#define ll long long

using namespace std;

int N = 1e5 + 7;
vector<int>par(N);

void up(int p) {
	while (p < N) {
		par[p]++;
		p += p & -p;
	}
}

int get(int p) {
	int res = 0;
	while (p) {
		res += par[p];
		p -= p & -p;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, ans = 0;
	cin >> n;
	vector<int>pos(n + 1);
	vector<int>out(n + 1);
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		pos[x] = i;
	}
	for (int i = 1; i <= n; ++i)
		cin >> out[i];

	for (int i = n; i; --i) {
		int x = pos[out[i]];
		ans += (get(x) != 0);
		up(x);
	}

	cout << ans << '\n';

	return 0;
}