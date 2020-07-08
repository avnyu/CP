#include<bits/stdc++.h>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;
	if(a == 9 && b == 1)
		cout << "9 10\n";
	else if (b == a + 1)
		cout << a << ' ' << b << '\n';
	else if (a == b)
		cout << a * 10 << ' ' << a * 10 + 1 << '\n';
	else
		cout << "-1\n";

	return 0;
}