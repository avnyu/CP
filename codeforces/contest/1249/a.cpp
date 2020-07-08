#include<bits/stdc++.h>
using namespace std;

int main() {

	int q;
	cin >> q;

	while (q--) {
		int n;
		cin >> n;

		vector<int>a(n);
		for (int i = 0; i < n; ++i)cin >> a[i];

		sort(a.begin(), a.end());

		bool add = 0;
		for (int i = 1; i < n; ++i)add |= (a[i] - a[i - 1] == 1);

		cout << 1 + add << '\n';
	}

	return 0;
}