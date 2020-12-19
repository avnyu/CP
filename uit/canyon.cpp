#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e2 + 7;
int L[N][N], R[N][N];
int n, m;


ll test(int h) {
	int w = 1e9 + 7;
	for (int i = 0; i < m - h; ++i) {
		w = min(w, n - L[i][i + h] - R[i][i + h]);
	}
	return 1LL * h * w * (w != int(1e9 + 7));
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; ++i) cin >> L[i][i];

	for (int i = 0; i < m; ++i) cin >> R[i][i];


	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j) {
			L[i][j] = max(L[i][j - 1], L[j][j]);
			R[i][j] = max(R[i][j - 1], R[j][j]);
		}

	ll ans = 0;
	for (int i = 1; i <= m; ++i)ans = max(ans, test(i));

	cout << ans << '\n';

	return 0;
}