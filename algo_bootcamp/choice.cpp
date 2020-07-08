#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5 + 7;
int n;
int ZA[N], ZB[N];

void Z_function(string &S, int Z[]) {
	int L = 0, R = 0;
	Z[0] = n;
	for (int i = 1; i < n; i++)
		if (i > R) {
			L = R = i;
			while (R < n && S[R] == S[R - L]) R++;
			Z[i] = R - L; R--;
		}
		else {
			int k = i - L;
			if (Z[k] < R - i + 1) Z[i] = Z[k];
			else {
				L = i;
				while (R < n && S[R] == S[R - L]) R++;
				Z[i] = R - L; R--;
			}
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s, inv_s = "";
	cin >> s;
	inv_s = string(s.begin(), s.end());
	reverse(inv_s.begin(), inv_s.end());
	n = int(s.size());

	Z_function(s, ZA);
	Z_function(inv_s, ZB);

	ll ans = (1LL * (n - 1) * (n - 2)) / 2;

	int a = 0, b = 0, c =  0, abc = 0;

	for (int i = 1; i <= (n - 1) / 2; ++i) {
		a += ZA[i] >= i;
		b += ZB[i] >= i;
		abc += ((ZA[i] >= i) & (ZB[i] >= i) & (i + i + i == n));
	}
	for (int i = n / 2 + 1; i < n; ++i) {
		c += ZA[n - i] >= i;
	}

	//cout << a << ' ' << b << ' ' << c << ' ' << abc << '\n'	;
	cout << ans - a - b - c + abc + abc << '\n';

	return 0;
}