#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	for (int i = 1; i * i <= n; ++i) {
		if (n % (i * i) == 0)ans = i * i;
	}
	cout << ans;
	return 0;
}