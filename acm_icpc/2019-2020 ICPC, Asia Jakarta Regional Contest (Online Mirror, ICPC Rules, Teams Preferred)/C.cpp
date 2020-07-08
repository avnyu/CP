#include<bits/stdc++.h>
using namespace std;

int N = 4e5 + 7;
int n, q, x;
int ax, ay, bx, by;
vector<int>a(N), b(N);

int up(vector<int>&st, int p, int v, int i = 1, int l = 1, int r = n) {
	if (p < l || p > r)return st[i];
	if (p == l && p == r)return st[i] = v;
	int m = (l + r) >> 1;
	return st[i] = up(st, p, v, i + i, l, m) | up(st, p, v, i + i + 1, m + 1, r);
}
int get(vector<int>&st, int b, int e, int i = 1, int l = 1, int r = n ) {
	if (l > e || r < b)return 0;
	if (b <= l && r <= e)return st[i];
	int m = (l + r) >> 1;
	return get(st, b, e, i + i, l, m) | get(st, b, e, i + i + 1, m + 1, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		cin >> x;
		up(a, i + 1, (x & 1 ? 1 : 2));
	}
	for (int i = 0; i < n; ++i) {
		cin >> x;
		up(b, i + 1, (x & 1 ? 1 : 2));
	}

	for (int i = 0; i < q; ++i) {
		cin >> ax >> ay >> bx >> by;
		if (ax > bx)swap(ax, bx);
		if (ay > by)swap(ay, by);
		int t1 = get(a, ax, bx);
		int t2 = get(b, ay, by);
		if (t1 == 1 && t2 == 1)cout << "YES\n";
		else if (t1 == 2 && t2 == 2)cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}