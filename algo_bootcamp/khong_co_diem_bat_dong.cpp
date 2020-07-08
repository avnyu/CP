#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool get_next(int p[], int ps, int n) {
	set<int>add;
	int nxt = n;
	for (int i = ps; i < n; ++i) {
		add.insert(p[i]);
		if (p[i] > p[ps] && p[i] < nxt)nxt = p[i];
	}
	if (nxt == n)return false;
	add.erase(nxt);
	p[ps++] = nxt;
	for (auto&i : add)p[ps++] = i;
	return true;
}

int main() {

	int n, t;
	cin >> n >> t;
	int p[n];
	for (int i = 0; i < n; ++i)p[i] = i;

	int cnt = 0;
	while (1) {
		bool chk = false;
		int w = -1;
		for (int i = 0; i < n; ++i)if (p[i] == i) {w = i; break;}
		
		if (w != -1) {
			while(!get_next(p, w--, n));
		}
		else {
			for (int i = 0; i < n; ++i)cout << p[i] + 1 << ' ';
			cout << '\n';
			t--;
			if (!t)break;
			if (!next_permutation(p, p + n)) {
				for (int i = 0; i < n; ++i)p[i] = i;
			}
		}
	}

	return 0;
}