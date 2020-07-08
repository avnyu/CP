#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;

		string s;
		bool chk = false;
		int cnt = 0;
		for (int i = 0; i < n; ++i){
			cin >> s;
			for (auto &j : s)cnt += j == '1';
			chk |= (int(s.size()) & 1);
		}

		cout << n - ((1 - chk) * (cnt & 1)) << '\n';
	}

	return 0;
}