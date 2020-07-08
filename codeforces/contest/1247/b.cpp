#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;

	vector<int>a(2e5 + 7), in(1e6 + 1);

	while (t--) {
		int n, k, d, cnt = 0;
		cin >> n >> k >> d;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			in[a[i]] = 0;
		}

		for (int i = 0; i < d; ++i) {
			if (in[a[i]] == 0)cnt++;
			in[a[i]]++;
		}

		int res = cnt;
		for (int i = d; i < n; ++i) {
			if (in[a[i - d]] == 1)cnt--;
			in[a[i - d]]--;

			if (in[a[i]] == 0)cnt++;
			in[a[i]]++;

			res = min(res, cnt);
		}
		cout << res << '\n';
	}

	return 0;
}