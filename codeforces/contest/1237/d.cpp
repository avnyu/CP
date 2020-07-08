#include<bits/stdc++.h>
#define ll long long

using namespace std;

int N = 2e5 + 2;
int n, oo = 1e9;
vector<int>it(N << 2);
vector<int>sav(N + N);
vector<int>a(N + N);

int up(int p, int v, int i = 1, int l = 0, int r = n + n - 1) {
	if (p < l || p > r)return it[i];
	if (p == l && p == r)return it[i] = v;
	int m = (l + r) >> 1;
	return it[i] = min(up(p, v, i + i, l, m), up(p, v, i + i + 1, m + 1, r));
}

int get(int b, int e, int i = 1, int l = 0, int r = n + n - 1) {
	if (e < l || b > r)return oo;
	if (b <= l && r <= e)return it[i];
	int m = (l + r) >> 1;
	return min(get(b, e, i + i, l, m), get(b, e, i + i + 1, m + 1, r));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
		up(i, a[i]);
		up(i + n, a[i]);
	}

	//for (int i = 0; i < n + n; ++i)cout << a[i] << ' '; cout << '\n';

	for (int i = 0; i < n; ++i) {
		int e = oo;
		int l = i + 1, r = i + n;
		while (l <= r) {
			int m = (l + r) >> 1;
			int x = get(l, m);
			bool chk = (a[i] & 1 ? (x <= (a[i] / 2)) : (x < (a[i] / 2)));
			if (chk) {
				e = m;
				r = m - 1;
			}
			else
				l = m + 1;
		}

		sav[i] = e;
		sav[i + n] = e + n;
	}

	for (int i = 0; i < n + n; ++i)up(i, sav[i]);

	//for (int i = 0; i < n + n; ++i)cout << sav[i] << ' '; cout << '\n';

	for (int i = 0; i < n; ++i) {
		int x = get(i, sav[i]);
		cout << (x < oo ? x - i : -1) << ' ';
	}
	cout << '\n';

	return 0;
}