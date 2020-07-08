#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int> >a(n, vector<int>(n));
	for ( auto &i : a )
		for ( auto &j : i )
			cin >> j;

	vector<int>ans(n);
	ans[0] = sqrt((ll)a[0][1] * a[0][2] / a[1][2]);

	cout << ans[0] << ' ';;
	for ( int i = 1; i < n; ++i )
		cout << a[0][i] / ans[0] << ' ';

	return 0;
}