#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int M = 1e9 + 7;
int N = 4e5 + 7;
int n, q;

struct mat {
	int val[2][2];
	bool rev;

	mat(int tl, int tr, int dl, int dr) {
		rev = 0;
		val[0][0] = tl;
		val[0][1] = tr;
		val[1][0] = dl;
		val[1][1] = dr;
	}

	void reverse() {
		rev ^= 1;
		swap(val[0][0], val[1][1]);
		swap(val[1][0], val[0][1]);
	}
};

mat mul(mat A, mat B) {
	mat res(0, 0, 0, 0);
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				res.val[i][j] = (1LL * A.val[i][k] * B.val[k][j] + res.val[i][j]) % M;

	return res;
}

mat A(1, 0, 1, 1), B(1, 1, 0, 1), D(1, 0, 0, 1);
vector<mat>it(N, D);

mat add(int p, char t, int i = 1, int l = 0, int r = n - 1) {
	if (p < l || p > r)return it[i];
	if (p == l && p == r)return it[i] = (t == 'A' ? A : B);
	int m = (l + r) >> 1;
	return it[i] = mul(add(p, t, i + i, l, m), add(p, t, i + i + 1, m + 1, r));
}

void upd_rev(int i) {
	if (!it[i].rev)return;
	it[i].rev = 0;

	if (i + i >= N)return;
	it[i + i].reverse();
	it[i + i + 1].reverse();
}
void upd(int i) {
	it[i] = mul(it[i + i], it[i + i + 1]);
}

void rev(int b, int e, int i = 1, int l = 0, int r = n - 1) {
	upd_rev(i);
	if (l > e || r < b)return;
	if (b <= l && r <= e) {
		it[i].reverse();
		return;
	}
	int m = (l + r) >> 1;
	rev(b, e, i + i, l, m);
	rev(b, e, i + i + 1, m + 1, r);
	upd(i);
}
mat get(int b, int e, int i = 1, int l = 0, int r = n - 1) {
	upd_rev(i);
	if (l > e || r < b)return D;
	if (b <= l && r <= e)return it[i];
	int m = (l + r) >> 1;
	mat res = mul(get(b, e, i + i, l, m), get(b, e, i + i + 1, m + 1, r));
	upd(i);
	return res;
}

void solve() {

	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		add(i, c);
	}

	for (int i = 0; i < q; ++i) {
		int t, l, r, a, b;
		cin >> t >> l >> r;
		l--, r--;

		if (t == 1) {
			rev(l, r);
		}
		else {
			cin >> a >> b;

			mat E(a, b, 0, 0);
			mat F = get(l, r);
			E = mul(E, F);
			cout << E.val[0][0] << ' ' << E.val[0][1] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in", "r", stdin);

	solve();

	return 0;
}