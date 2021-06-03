#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5;

int n, s, len;

int a[N];

int lg[N];
int STmin[N][25], STmax[N][25];

void build() {
    lg[1] = 0;
    for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;

    for (int i = 0; i < n; ++i) { STmin[i][0] = STmax[i][0] = a[i]; }

    for (int j = 1; j < 25; ++j) {
        for (int i = 0; i + (1 << j) - 1 <= n; ++i) {
            STmin[i][j] =
                min(STmin[i][j - 1], STmin[i + (1 << (j - 1))][j - 1]);
            STmax[i][j] =
                max(STmax[i][j - 1], STmax[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int dif(int l, int r) {
    int j = lg[r - l + 1];

    int mn = min(STmin[l][j], STmin[r - (1 << j) + 1][j]);
    int mx = max(STmax[l][j], STmax[r - (1 << j) + 1][j]);

    return mx - mn;
}

int dp[N];
deque<int> q;

void solve() {
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) dp[i] = INF;

    int last = 0;
    for (int i = 0; i < n; ++i) {
        while (dif(last, i) > s) {
            if (!q.empty() && q.front() == last) { q.pop_front(); }
            ++last;
        }

        int r = i + 1 - len;

        if (r >= last) {
            while (!q.empty() && dp[q.back()] >= dp[r]) { q.pop_back(); }
            q.push_back(r);
        }

        if (!q.empty()) {
            dp[i + 1] = dp[q.front()] + 1;
        } else {
            dp[i + 1] = INF;
        }
    }

    // for (int i = 1 ; i <= n ; ++i) cout << dp[i] << " ";
    // cout << "\n";

    if (dp[n] >= INF) {
        cout << -1;
    } else {
        cout << dp[n];
    }
}

int main() {
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> len;
    for (int i = 0; i < n; ++i) cin >> a[i];

    build();

    solve();
}
