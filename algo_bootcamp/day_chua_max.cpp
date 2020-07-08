#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, b;
	cin >> n >> b;
	int a[n + 2];
	a[0] = a[n + 1] = int(1e9 + 7);
	for ( int i = 1; i <= n; ++i ) cin >> a[i];

	int l[n + 2], r[n + 2], s[n + 2], j = 0;
	s[j] = 0;

	for ( int i = 1; i <= n; ++i ) {
		while ( a[i] > a[s[j]] ) j--;
		l[i] = s[j];
		s[++j] = i;
	}

	for ( int i = 0; i < n + 2; ++i ) s[i] = 0;
	j = n + 1;
	s[j] = n + 1;

	for ( int i = n; i; --i ) {
		while ( a[i] >= a[s[j]] ) j++;
		r[i] = s[j];
		s[--j] = i;
	}

	ll ans = 0;

	for ( int i = 1; i <= n; ++i ) {
		if ( a[i] == b ) {
			ans += 1LL * (i - l[i]) * (r[i] - i);
		}
	}

	cout << ans << '\n';

	return 0;
}