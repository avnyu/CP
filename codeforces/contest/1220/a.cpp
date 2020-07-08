#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int cnt[2] = {};
	string s;
	cin >> s;
	for ( auto &i : s ) {
		cnt[0] += i == 'n';
		cnt[1] += i == 'z';
	}

	while ( cnt[0]-- )
		cout << "1 ";
	while ( cnt[1]-- )
		cout << "0 ";

	return 0;
}