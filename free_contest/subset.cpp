#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int>a(k, 0);

	for ( int i = 0; i < n; ++i ) {
		int x;
		cin >> x;
		a[x % k]++;
	}

	int ans = 0;
	for ( int i = 1; i < (k + 1) / 2; ++i ) {
		ans += max(a[i], a[k - i]);
	}
	ans += min(1, a[0]);
	if ( k % 2 == 0 )
		ans += min(1, a[k / 2]);
	cout << ans << endl;

	return 0;
}