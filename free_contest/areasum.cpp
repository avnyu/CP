#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	ll a = 0, b = 0, x, M = 1e9 + 7;

	for ( int i = 0; i < n; ++i ) {
		cin >> x;
		a = (a + (1 - n + 2 * i) * x) % M;
	}
	for ( int i = 0; i < m; ++i ) {
		cin >> x;
		b = (b + (1 - m + 2 * i) * x) % M;
	}

	cout << (a * b) % M;

	return 0;
}