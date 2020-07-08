#include <bits/stdc++.h>
#define pii pair<int, int>
#define tiii tuple<int, int, int>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int64_t n;
	cin >> n;
	vector<int>a(n);
	for ( auto &i:a )
		cin >> i;
	sort(a.begin(), a.end());
	int64_t dis = 0;
	for ( int i = 0; i < n; ++i ) {
		if ( i & 1 )
			dis = dis - a[i];
		else
			dis = dis + a[i];
	}

	cout << dis;

	return 0;
}