#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		cout << ((x - 1 + n - 1) % n) + 1 << ' ';
	}

	return 0;
}