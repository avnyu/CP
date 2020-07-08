#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<pair<int, int>>a(n), ans(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < n; ++i) {
		ans[a[i].second] = {a[i].first, i + 1};
	}

	for (auto&i : ans)cout << i.first << ' ' << i.second << '\n';

	return 0;
}