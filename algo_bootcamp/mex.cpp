#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<bool>in(1e5 + 7);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		in[x] = 1;
	}
	for (int i = 1; i < int(1e5 + 7); ++i) {
		k -= in[i] == 0;
		if (k == 0) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << int(1e5 + 6) + k << '\n';

	return 0;
}