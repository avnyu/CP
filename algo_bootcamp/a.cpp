#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in", "r", stdin);

	int n, m;
	cin >> n >> m;
	vector<int>a(n), b(m);
	vector<vector<int>>dp(n + 1, vector<int>(n + 1));
	vector<vector<int>>trace(m + 1, vector<int>(m + 1));
	vector<vector<int>>nextPos(n, vector<int>(26, -1));

	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < m; ++i)cin >> b[i];

	for (int i = n - 1; i; --i) {
		for (int j = 0; j < 26; ++j)nextPos[i - 1][j] = nextPos[i][j];
		nextPos[i - 1][s[i] - 97] = i;
	}

	for(int i=0;i<m;++i){
		
	}

	return 0;
}