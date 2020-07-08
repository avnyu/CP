#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, oo = 1e9;
int N = 50005;
vector<int>d(4, oo);
vector<vector<int>>a(N, vector<int>(d));
vector<pair<int, int>>res;

void rem(int d1, int d2, int d3) {
	sort(a.begin(), a.end(), [&](vector<int>&x, vector<int>&y) {
		if (x[d1] != y[d1])return x[d1] < y[d1];
		if (x[d2] != y[d2])return x[d2] < y[d2];
		if (x[d3] != y[d3])return x[d3] < y[d3];
		return x[3] < y[3];
	});

	for (int i = 1; i < n; ++i) {
		vector<int>&x = a[i - 1], &y = a[i];

		if (x[d1] == y[d1] && x[d2] == y[d2] && x[3] != oo) {
			res.push_back({x[3], y[3]});
			x = y = d;
		}
	}
}

void rem2(int d1, int d2, int d3) {
	sort(a.begin(), a.end(), [&](vector<int>&x, vector<int>&y) {
		if (x[d1] != y[d1])return x[d1] < y[d1];
		if (x[d2] != y[d2])return x[d2] < y[d2];
		if (x[d3] != y[d3])return x[d3] < y[d3];
		return x[3] < y[3];
	});

	for (int i = 1; i < n; ++i) {
		vector<int>&x = a[i - 1], &y = a[i];

		if (x[d1] == y[d1] && x[3] != oo) {
			res.push_back({x[3], y[3]});
			x = y = d;
		}
	}
}

void rem3() {
	sort(a.begin(), a.end());

	for (int i = 1; i < n; i += 2) {
		vector<int>&x = a[i - 1], &y = a[i];

		if (x[3] != oo)res.push_back({x[3], y[3]});
		x = y = d;
	}
}

void show() {
	cout << "show\n";
	for (int i = 0; i < n; ++i)
		cout << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << ' ' << a[i][3] << '\n';
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		a[i][3] = i + 1;
	}

	rem(0, 1, 2);
	rem(1, 2, 0);
	rem(2, 0, 1);
	rem2(0, 1, 2);
	rem2(1, 2, 0);
	rem2(2, 0, 1);
	rem3();

	for (auto&i : res)cout << i.first << ' ' << i.second << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	solve();

	return 0;
}