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

const int N = 1e5 + 1;
vector<int> pos_x(N, 0), pos_y(N, 0), neg_x(N, 0), neg_y(N, 0);
vvi g(N), h(N);

ll _sqrt(ll x) {
    ll l = 0, r = 1e9;
    while (l <= r) {
        ll m = (l + r) >> 1;
        if (m * m == x)
            return m;
        else if (m * m < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

void init() {
    vi square, maxPrime(N), need(N, 1);
    for (int i = 1; i * i < N; ++i) square.push_back(i * i);
    iota(all(maxPrime), 0);

    for (int i = 2; i < N; ++i)
        if (maxPrime[i] == i)
            for (int j = i + i; j < N; j += i) maxPrime[j] = i;

    for (int i = 2; i < N; ++i) {
        int j = i, x = 1, cnt = 0;
        while (j > 1) {
            if (maxPrime[j] != x) {
                need[i] *= (cnt & 1 ? x : 1);
                x = maxPrime[j];
                cnt = 1;
            } else
                cnt++;
            j /= maxPrime[j];
        }
        need[i] *= (cnt & 1 ? x : 1);
    }

    for (int i = 1; i < N; ++i)
        for (int j = 0; need[i] * square[j] < N && j < square.size(); ++j) {
            g[i].push_back(need[i] * square[j]);
            h[i].push_back(_sqrt(1LL * i * need[i] * square[j]));
        }
}

void solve() {
    int n, m;
    cin >> n >> m;
    fill(all(pos_x), 0);
    fill(all(pos_y), 0);
    fill(all(neg_x), 0);
    fill(all(neg_y), 0);
    int o = 0, cntx = n, cnty = m;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            o++;
            cntx--;
        } else if (a < 0)
            neg_x[-a] = 1;
        else
            pos_x[a] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            o++;
            cnty--;
        } else if (a < 0)
            neg_y[-a] = 1;
        else
            pos_y[a] = 1;
    }

    ll res = 0;
    for (int i = 1; i < N; ++i) {
        if (pos_x[i])
            for (int j = 0; j < int(h[i].size()); ++j)
                if (neg_x[g[i][j]]) res += pos_y[h[i][j]] + neg_y[h[i][j]];

        if (pos_y[i])
            for (int j = 0; j < int(h[i].size()); ++j)
                if (neg_y[g[i][j]]) res += pos_x[h[i][j]] + neg_x[h[i][j]];
    }
    res += 1LL * o * cntx * cnty;

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    init();

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}