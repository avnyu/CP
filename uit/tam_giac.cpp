#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input", "r", stdin);

	ll e[3];
	cin >> e[0] >> e[1] >> e[2];
	sort(e, e + 3);
	cout << (e[0] + e[1] <= e[2] ? (e[2] - e[1] - e[0]) / 2 + 1 : 0) << '\n';

	return 0;
}