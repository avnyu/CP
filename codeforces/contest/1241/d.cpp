#include <bits/stdc++.h>
#define lli long long
using namespace std;

int N = 3e5 + 7;
int n;
vector<int> lef, rig, cnt, dp;

void solve() {
    cin >> n;
    int all = 0;

    cnt.assign(n + 1, 0);
    lef.assign(n + 1, N);
    rig.assign(n + 1, -1);
    dp.assign(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (cnt[x] == 0) all++;
        cnt[x]++;
        lef[x] = min(lef[x], i);
        rig[x] = max(rig[x], i);
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (lef[i] == N) {
            lef[i] = lef[i - 1];
            rig[i] = rig[i - 1];
            dp[i] = dp[i - 1];
            continue;
        }

        if (lef[i] > rig[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;

        res = max(res, dp[i]);
    }

    cout << all - res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in", "r", stdin);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}