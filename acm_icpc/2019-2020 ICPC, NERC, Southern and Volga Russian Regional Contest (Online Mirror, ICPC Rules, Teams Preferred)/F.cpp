#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int res = 1e9;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0)
			res = min(res, i + i + n / i + n / i);
	}
	cout << res << '\n';

	return 0;
}