#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	srand(time(NULL));
	string s = "";
	for ( int i = 0; i < 10000; ++i )
		s += char(97 + rand() % 26);

	node *root = new node();

	for ( int i = 0; i < int(s.size()); ++i )
		add(root, s, i);

	cout << cal(root) - 1 << endl;
	return 0;
}