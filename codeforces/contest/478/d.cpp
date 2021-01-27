#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int r, g;
    cin >> r >> g;
    const int M = 1e9 + 7;
    int h = 0;

    for (int add = 1 << 10; add; add >>= 1)
        if ((h + add) * (h + add + 1) <= (r + g) * 2) h += add;
    
    if (r > g) swap(r, g);
    vvi dp(2, vi(r + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= h; ++i) {
        auto &cur = dp[i & 1];
        auto &prv = dp[(i & 1) ^ 1];
        fill(all(cur), 0);
        for (int j = 0; j <= r; ++j) {
            cur[j] = (cur[j] + prv[j]) % M;
            if (j + i <= r) cur[j + i] = (cur[j + i] + prv[j]) % M;
        }
        // print(i);
        // for (int j = 0; j <= r; ++j) cout << cur[j] << " \n"[j == r];
    }

    ll res = 0;
    int k = h * (h + 1) / 2;
    for (int i = 0; i <= r; ++i)
        if (i <= k && i + g >= k) {
            res = (res + dp[h & 1][i]) % M;
            // print(i, dp[h & 1][i]);
        }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}