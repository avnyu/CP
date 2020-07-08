#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, N = 1e5 + 1;
vector<ll>a(N), cnt(N), chk(N);
vector<vector<int>>fact(N);
vector<vector<ll>>p(N, vector<ll>(41, N));

void init() {
	for (int i = 2; i < N; ++i) {
		if (chk[i])continue;

		int j = i;
		while (j < N) {
			chk[j] = 1;
			fact[j].push_back(i);
			j += i;
		}
	}

	for (int i = 1; i < N; ++i) {
		p[i][0] = 1;

		for (int j = 1; j < 41; ++j) {
			p[i][j] = p[i][j - 1] * i;
			if (p[i][j] > N) {
				p[i][j] = N;
				break;
			}
		}
	}
}

ll cal(int x) {
	ll add = 1, pi, tmp;

	for (auto&i : fact[x]) {
		pi = 0;
		while (x % i == 0) {
			pi++;
			x /= i;
		}

		pi = (k - pi % k) % k;
		add *= p[i][pi];
		if (add >= N)return 0;
	}

	ll res = 0, j;
	for (int i = 1;; ++i) {
		j = p[i][k] * add;
		if (j >= N)break;
		res += cnt[j];
	}

	return res;
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	init();

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	if (k > 40) {
		cout << cnt[1] * (cnt[1] - 1) / 2 << '\n';
		return 0;
	}

	ll res = 0;

	for (int i = 0; i < n; ++i) {
		cnt[a[i]]--;
		res += cal(a[i]);
	}

	cout << res << '\n';

	return 0;
}