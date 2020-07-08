#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T>& a);

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vvi pos(n, vi(p + 1));
    for (int i = 0; i < n; ++i) cin >> pos[i][p];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j) cin >> pos[i][j];
    sort(all(pos), [](vi& a, vi& b) { return a.back() > b.back(); });

    vi p2(p + 1, 1);
    for (int i = 0; i < p; ++i) p2[i + 1] = p2[i] << 1;

    vector<vector<ll>> dp(n + 1, vector<ll>(p2[p], -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int msk = 0; msk < p2[p]; ++msk) {
            if (dp[i][msk] == -1) continue;

            for (int j = 0; j < p; ++j) {
                if ((msk & p2[j]) == 0)
                    dp[i + 1][msk | p2[j]] =
                        max(dp[i + 1][msk | p2[j]], dp[i][msk] + pos[i][j]);
            }

            dp[i + 1][msk] = max(
                dp[i + 1][msk],
                dp[i][msk] +
                    (max(i - __builtin_popcount(msk), 0) < k ? pos[i][p] : 0));
        }
    }

    cout << dp[n][p2[p] - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}