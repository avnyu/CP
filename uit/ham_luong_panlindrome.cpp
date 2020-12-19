#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	string s;
	cin >> s;
	ll a[128] = {};
	ll ans = 0;
	for (auto&i : s)a[i]++;
	for (int i = 0; i < 128; ++i) {
		ans += a[i] * (a[i] + 1LL) / 2LL;
	}
	cout << ans << '\n';
}

int cnt(string s) {
	int n = s.size(), res = 0;
	for (int i = 0; i < n; ++i) {
		int j = 0;
		while (i + j < n && i - j >= 0 && s[i + j] == s[i - j])j++;
		res += j;
	}
	for (int i = 1; i < n; ++i) {
		int j = 0;
		while (i - 1 - j >= 0 && i + j < n && s[i - 1 - j] == s[i + j])j++;
		res += j;
	}
	return res;
}
void test() {
	string s;
	for (int i = 0; i < 10; ++i)
		s += char('a' + rand() % 3);

	sort(s.begin(), s.end());
	int mx = 0;
	while (1) {
		mx = max(mx, cnt(s));
		if (!next_permutation(s.begin(), s.end()))break;
	}
	sort(s.begin(), s.end());

	cout << mx << '\n';
	while (1) {
		int tmp = cnt(s);
		if (tmp == mx)cout << s << '\n';
		if (!next_permutation(s.begin(), s.end()))break;
	}
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in", "r", stdin);

	test();

	return 0;
}