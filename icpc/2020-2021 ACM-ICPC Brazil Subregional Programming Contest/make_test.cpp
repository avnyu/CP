#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n = 50, k = 25;
    cout << n << " "  << k << '\n';
    for (int i = 0; i < n; ++i) cout << (1LL << i) << " \n"[i == n - 1];
    cout << 0 << " " << (1LL << 50) << '\n';
    
	return 0;
}
