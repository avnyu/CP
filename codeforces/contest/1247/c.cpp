#include<bits/stdc++.h>
using namespace std;

int main() {

	long long n, p;
	cin >> n >> p;

	for (int i = 1; i < 64; ++i) {
		long long p2 = n - p * i;
		long long tmp = p2;

		int cnt = 0;
		if (p2 < 0)break;
		while (p2) {
			cnt += p2 & 1;
			p2 >>= 1;
		}

		if (cnt <= i && i <= tmp) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << "-1\n";

	return 0;
}