#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int n = int(s.size());

	char c = 'z';
	for ( auto &i : s )
		if ( c < i ) {
			cout << "Ann\n";
		}
		else {
			cout << "Mike\n";
			c = i;
		}

	return 0;
}