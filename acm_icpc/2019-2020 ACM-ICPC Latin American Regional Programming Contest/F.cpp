#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int N = 5e3 + 1, M = 1e9 + 7;
vector<vector<int>> save(N, vector<int>(N, -1));

int s, b;
int dp(int si, int bi) {
    if (bi < 0) return 0;
    if (bi == 0) return 1;
    if (si == 0) return 0;
    if (si == 1) return 1;
    if (save[si][bi] > -1) return save[si][bi];
    return save[si][bi] = (1LL * dp(si, bi - si) + dp(si - 1, bi) * 2 -
                           dp(si - 2, bi) + M) %
                          M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> b;
    cout << dp(s, b - s) << '\n';

    return 0;
}