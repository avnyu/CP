#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

int solve() {
    int n;
    cin >> n;
    int cnt[4][4] = {};
    for (int i = 0; i < n; ++i) {
        char c;
        int t;
        cin >> c >> t;
        cnt[c - 'A'][t / 3 - 1]++;
    }
    // for (int i = 0; i < 4; ++i)
    //     for (int j = 0; j < 4; ++j) cout << cnt[i][j] << " \n"[j == 3];
    int p[] = {0, 1, 2, 3}, x[4];
    int res = -1e9;
    while (1) {
        for (int i = 0; i < 4; ++i) x[i] = cnt[p[i]][i];
        sort(x, x + 4);
        res = max(res, x[0] * 25 + x[1] * 50 + x[2] * 75 + x[3] * 100 -
                           100 * ((x[0] == 0) + (x[1] == 0) + (x[2] == 0) +
                                  (x[3] == 0)));
        if (!next_permutation(p, p + 4)) break;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;

    int res = 0;
    while (t--) {
        int x = solve();
        cout << x << '\n';
        res += x;
    }
    cout << res << '\n';
    return 0;
}