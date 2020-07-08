#include <bits/stdc++.h>

using namespace std;

int main() {
	string pa = "bcdfghjklmnpqrstvxz";
	string s;
	int f[19][19] = {};
	int ans = -1, m = -1;
	cin >> s;
	for (int i = 1; i < s.size(); ++i) {
		if (pa.find(s[i - 1]) != string::npos && pa.find(s[i]) != string::npos) {
			f[pa.find(s[i - 1])][pa.find(s[i])]++;
			f[pa.find(s[i])][pa.find(s[i - 1])]++;
		}
	}

	for (int msk = 0; msk < (1 << 19); ++msk) {
		int x = 0;
		for (int j = 0; j < 19; ++j)
			for (int k = j + 1; k < 19; ++k) {
				int tmpx = ((1 << j) & msk);
				int tmpy = ((1 << k) & msk);
				if (tmpx == 0 && tmpy > 0) {
					x += f[j][k];
				}
				if (tmpx > 0 && tmpy == 0) {
					x += f[j][k];
				}
			}
		if (x > ans) {
			ans = x;
			m = msk;
		}
	}
	for (auto&i : s) {
		if (pa.find(i) != string::npos)
			if (m & (1 << pa.find(i))) {
				i -= 32;
			}
	}
	cout << s << endl;
	return 0;
}