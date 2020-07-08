#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		int x = min(b, c / 2);
		int ans = x * 3;
		b -= x;
		x = min(a, b / 2);
		ans += x * 3;
		cout << ans << '\n';
	}

	return 0;
}