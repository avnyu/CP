#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	int ans[10] = {0, 1, 1, 3, 1, 1, 3, 7, 1, 9};
	int nxt[10] = {0, 1, 1, 3, 2, 1, 3, 7, 4, 9};
	while (t--) {
		string s;
		cin >> s;

		int sav = 0, x = 0;
		for (int i = int(s.size()) - 1; i >= 0; --i) {
			x = sav + s[i] - '0';
			sav = x / 10;
			x %= 10;
			sav += nxt[x];
		}
		cout << ans[sav] << '\n';
	}

	return 0;
}