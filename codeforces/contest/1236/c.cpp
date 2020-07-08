#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>>a(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = n * i + j + 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[j][(i + j) % n] << ' ';
		}
		cout << '\n';
	}

	return 0;
}