#include<bits/stdc++.h>
using namespace std;
 
int main() {
 
	vector<int>p, res;
 
	int q;
	cin >> q;
 
	while (q--) {
 
		int n;
		cin >> n;
 
		p.assign(n, 0);
		res.assign(n, -1);
 
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			p[i]--;
		}
 
		for (int i = 0; i < n; ++i) {
			if (res[i] != -1)continue;
			int cnt = 1;
			int b = p[i];
 
			while (b != i) {
				b = p[b];
				cnt++;
			}
 
			res[i] = cnt;
			b = p[i];
			while (b != i) {
				res[b] = cnt;
				b = p[b];
			}
		}
 
		for (int i = 0; i < n; ++i)
			cout << res[i] << ' ';
		cout << '\n';
 
		p.clear();
		res.clear();
	}
 
	return 0;
}