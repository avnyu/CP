#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 1e9 + 7;
	string s;
	cin >> s;
	int n = s.size();

	ll dp[2][11] = {};
	int p = 0, p1;
	for ( int i = 0; i < 11; ++i ) dp[p][i] = 1;

	bool chk = false;
	for ( int i = 2; i < n; i += 3 ) {
		p = (p + 1) % 2;
		p1 = (p + 1) % 2;
		for ( int i = 0; i < 11; ++i ) dp[p][i] = 0;

		int x = (s[i - 2] - '0') * 100 + (s[i - 1] - '0') * 10 + (s[i] - '0');
		int c1 = s[i - 2] - '0', c2 = s[i - 1] - '0', c3 = s[i] - '0';
		int k1 = c2 * 10 + c3;
		int k2 = c1 * 10 + c3;
		int k3 = c1 * 10 + c2;

		if ( x > 99 && x < 123 ) dp[p][10] = 1;
		else chk = true;

		if ( c1 == c2 && k1 == k2 ) k2 = 0;
		if ( c1 == c3 && k1 == k3 ) k3 = 0;
		if ( c2 == c3 && k2 == k3 ) k3 = 0;

		if ((k1 > 64 && k1 < 91) || (k1 > 96 && k1 < 100)) dp[p][c1]++;
		if ((k2 > 64 && k2 < 91) || (k2 > 96 && k2 < 100)) dp[p][c2]++;
		if ((k3 > 64 && k3 < 91) || (k3 > 96 && k3 < 100)) dp[p][c3]++;

		for ( int i = 0; i < 10; ++i ) dp[p][i] = ((dp[p][i] + dp[p][10]) * dp[p1][i]) % M;
		dp[p][10] = (dp[p][10] * dp[p1][10]) % 10;
	}

	ll ans = 0;
	for ( int i = 0; i < 11; ++i ) ans = (ans + dp[p][i]) % M;
	cout << (chk ? ans: dp[p][10]) << '\n';

	return 0;
}