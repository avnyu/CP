#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e3;
bool a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, d, k;
	cin >> n >> d >> k;

	int i = 1e3, j = 1e3, s = 0, cntd = d;
	a[i][j] = 1;
	//n--;
	int mnx = i, mny = j, mxx = i, mxy = j;

	while ( n-- ) {
		if ( cntd == 0 ) {
			s = (s + 1) % 4;
			if ( s % 2 == 0 )d *= k;
			cntd = d;
		}
		if ( s == 0 ) a[i][++j] = 1;
		else if ( s == 1 ) a[--i][j] = 1;
		else if ( s == 2 ) a[i][--j] = 1;
		else a[++i][j] = 1;

		//cout << i << ' ' << j << '\n';
		mnx = min(mnx, i);
		mny = min(mny, j);
		mxx = max(mxx, i);
		mxy = max(mxy, j);
		cntd--;
	}

	cout << mxx - mnx + 1 << ' ' << mxy - mny + 1 << '\n';
	for ( int i = mnx; i <= mxx; ++i ) {
		for ( int j = mny; j <= mxy; ++j )
			cout << (a[i][j] ? '*' : '.');
		cout << '\n';
	}

	return 0;
}