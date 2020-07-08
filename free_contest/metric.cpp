#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int64_t n, p, q, M = int(1e9 + 7);
vector<pii>a;
int64_t ans = 0;

void calc_p() {
	for (int i = q; i < n; ++i) {
		if (a[i].first == a[q].first) {
			p = i;
			return;
		}
	}
	p = n;
}
void calc_ep() {
	for (int i = q; i < n; ++i) {
		if (a[i] == a[q]) {
			p = i;
			return;
		}
	}
	p = n;
}
void calc_q() {
	for (int i = p; i < n; ++i) {
		if (a[i].first != a[p].first) {
			q = i;
			return;
		}
	}
	q = n;
}
void calc_eq() {
	for (int i = p; i < n; ++i) {
		if (a[i] != a[p]) {
			q = i;
			return;
		}
	}
	q = n;
}
int64_t calc() {
	p = 0, q = 0;
	int64_t rs = 0;
	while (1) {
		calc_p();
		if (p < n) {
			calc_q();
			rs += (q - p) * (q - p - 1) / 2;
		}
		else break;
	}
	return rs;
}
int64_t calc_e() {
	p = 0, q = 0;
	int64_t rs = 0;
	while (1) {
		calc_ep();
		if (p < n) {
			calc_eq();
			rs += (q - p) * (q - p - 1) / 2;
		}
		else break;
	}
	return rs;
}
int main() {
	cin >> n;
	a.resize(n);
	for(auto&i:a)
		cin>>i.first>>i.second;
	a.push_back({M, M + 1});
	sort(a.begin(),a.end());
	ans = calc();
	for(auto&i:a)
		swap(i.first,i.second);
	sort(a.begin(), a.end());
	ans += calc();
	ans -= calc_e();
	cout << ans;
	return 0;
}