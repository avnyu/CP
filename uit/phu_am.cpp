#include <bits/stdc++.h>

using namespace std;

bool chk(char c) {
	return !(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'w' || c == 'y' || c == 'u');
}

int main() {
	string s;
	cin >> s;
	int cnt[26][26] = {};
	map<char, int>pos;
	int p = 0;
	for (int i = 0; i < 26; ++i) {
		char c = char(i + 'a');
		if (!chk(c))continue;
		pos[c] = p++;
	}
	for (int i = 1; i < int(s.size()); ++i) {
		if (chk(s[i - 1]) && chk(s[i])) {
			cnt[pos[s[i - 1]]][pos[s[i]]]++;
			cnt[pos[s[i]]][pos[s[i - 1]]]++;
		}
	}
	int ans = 0, max_cnt = 0;
	for (int i = 0; i < (1 << 19); ++i) {
		int tmp_cnt = 0;
		for (int j = 0; j < 19; ++j)
			for (int k = j + 1; k < 19; ++k) {
				if ((i & (1 << j)) && !(i & (1 << k)))
					tmp_cnt += cnt[j][k];
				if (!(i & (1 << j)) && (i & (1 << k)))
					tmp_cnt += cnt[j][k];
			}
		if (tmp_cnt > max_cnt) {
			max_cnt = tmp_cnt;
			ans = i;
		}
	}

	for (auto&i : s) {
		if (chk(i) && ((1 << pos[i]) & ans))i -= 32;
	}

	cout << s << '\n';

	return 0;
}