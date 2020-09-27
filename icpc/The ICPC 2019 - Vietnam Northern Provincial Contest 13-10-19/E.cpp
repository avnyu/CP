#include <bits/stdc++.h>
using namespace std;

const int m = 30010;
vector<vector<int>> divisors;

void init() {
	divisors.resize(m);
	for (int i = 1; i < m; ++i) {
		for (int j = i; j < m; j += i) {
			divisors[j].push_back(i);
		}
	}
}

int solve_1(int a, int b) {
	return -b / a;
}

int solve_2(int a, int b, int c) {
	long long d = 1LL * b * b - 4LL * a * c;
	if (d < 0) {
		return 0;
	}
	long long sd = (long long) sqrt(d);
	if (sd * sd != d) {
		return 0;
	}
	set<int> s;
	if ((-sd - b) % (2LL * a) == 0) {
		s.insert((-sd - b) / (2LL * a));
	}
	if ((sd - b) % (2LL * a) == 0) {
		s.insert((sd - b) / (2LL * a));
	}
	if (s.empty()) {
		return 0;
	}
	return *s.begin();
}

int solve_3(int a, int b, int c, int d) {
	if (d == 0) {
		return min(0, solve_2(a, b, c));
	}
	int absd = abs(d);
	int len = (int) divisors[absd].size();
	for (int i = len - 1; i >= 0; --i) {
		long long x = -divisors[absd][i];
		if (x * x * x * a + x * x * b + x * c + d == 0) {
			return x;
		}
	}
	for (int i = 0; i < len; ++i) {
		long long x = divisors[absd][i];
		if (x * x * x * a + x * x * b + x * c + d == 0) {
			return x;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	init();
	int notests = 1;
	cin >> notests;
	while (notests--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = n; i >= 0; --i) {
			cin >> a[i];
		}
		if (n == 1) {
			cout << solve_1(a[1], a[0]) << '\n';
			continue;
		}
		if (n == 2) {
			cout << solve_2(a[2], a[1], a[0]) << '\n';
			continue;
		}
		if (n == 3) {
			cout << solve_3(a[3], a[2], a[1], a[0]) << '\n';
			continue;
		}
	}
	return 0;
}