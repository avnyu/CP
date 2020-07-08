#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int64_t>>d;


using namespace std;

void calc(int x, int y, int mask, int next_mask) {
	if (x == m)return;
	if (y >= n)d[x + 1][next_mask] += d[x][mask];
	else {
		int my_mask = 1 << y;
		if (mask & my_mask)
			calc(x, y + 1, mask, next_mask);
		else {
			calc(x, y + 1, mask, next_mask | my_mask);
			if (y + 1 < n && !(mask & my_mask) && !(mask & (my_mask << 1)))
				calc(x, y + 2, mask, next_mask);
		}
	}
}

int main() {
	cin >> n >> m;
	if ((n * m) & 1) {cout << "0"; return 0;}
	if (n > m)swap(n, m);
	d.resize(m + 1, vector<int64_t>(1 << n));
	d[0][0] = 1;
	for (int x = 0; x < m; ++x)
		for (int mask = 0; mask < (1 << n); ++mask)
			calc(x, 0, mask, 0);

	cout << d[m][0] << endl;
	return 0;
}