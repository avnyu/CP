#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

	int w, l, h;
	cin >> w >> l >> h;

	if (l < w)swap(l, w);
	if (double(w) / h < double(2)) {
		cout << "bad\n";
		return 0;
	}
	if (double(l) / w > double(2)) {
		cout << "bad\n";
		return 0;
	}
	cout << "good\n";

	return 0;
}