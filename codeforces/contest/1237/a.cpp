#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, bal = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (abs(x) % 2 == 0)cout << x / 2 << ' ';
		else {
			x = x / 2 + (x > 0);
			if (bal > 0) {
				cout << x - 1 << ' ';
				bal--;
			}
			else {
				cout << x << ' ';
				bal++;
			}
		}
	}

	return 0;
}