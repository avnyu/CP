#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>>a(n);
	priority_queue<int>q1, q2;
	ll s = 0, s1 = 0, s2 = 0;

	for (auto&i : a){
		cin >> i.first >> i.second;
		s += i.second;
	}

	sort(a.begin(), a.end());

	int l = 0;
	for (int i = 0; i <= n; ++i) {
		while (l < n && a[l].first == i) {
			p1.push(a[l].second)
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}