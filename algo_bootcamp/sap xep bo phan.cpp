#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 3e6 + 7;
int ft[N], a[N], b[N];
ll nt, des;

void up(int p, int v) {
	for (; p < N; p += p & -p)
		ft[p] += v;
}
int get(int p) {
	int rs = 0;
	for (; p; p -= p & -p)
		rs += ft[p];
	return rs;
}

int main() {

	freopen("input", "r", stdin);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {cin >> a[i]; b[i] = a[i];}
	sort(b, b + n);

	cout << n << '\n';
	for (int i = 0; i < n; ++i)cout << a[i] << ' ';
	cout << '\n';

	ll nt = 0;
	for (int i = 0; i < n; ++i) {
		int small_before = get(a[i] - 1);
		int small_and_equal =  get(a[i]);
		int small_total = lower_bound(b, b + n, a[i]) - b;
		int small_after = small_total - small_before;
		int big_before = i - small_and_equal;
		cout << a[i] << ' ' << big_before << ' ' << small_after << '\n';

		des = max(des, 0LL + small_after + big_before);
		nt = nt + big_before;
		up(a[i], 1);
	}

	cout << nt - des << '\n';

	return 0;
}