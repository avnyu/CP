#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define vi vector<int>
#define vvi vector<vector<int>>
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int M = 1e9 + 7;

int fpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = (1LL * res * x) % M;
        n >>= 1;
        x = (1LL * x * x) % M;
    }
    return res;
}
int gcdex(int x, int m) { return fpow(x, m - 2); }

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    if (k == 1) {
        cout << "0\n";
        return;
    }

    for (auto& i : a) i = (i + M) % M;
    // for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
    vi nCk(n + 1, 1);
    vi fac(n + 1, 1);
    for (int i = 2; i <= n; ++i) fac[i] = (1LL * fac[i - 1] * i) % M;
    // for (int i = 0; i <= n; ++i) cout << fac[i] << " \n"[i == n];
    for (int i = k; i <= n; ++i) {
        ll tmp = fac[i - 2];
        tmp = (tmp * gcdex(fac[k - 2], M)) % M;
        nCk[i] = (tmp * gcdex(fac[i - k], M)) % M;
        if (nCk[i] == 0) nCk[i] = 1;
    }
    for (int i = k + 1; i <= n; ++i) nCk[i] = (nCk[i - 1] + nCk[i]) % M;

    ll max_sum = 0, min_sum = 0;
    int j = k;
    for (int i = k - 1; i < n; ++i)
        max_sum = (max_sum + 1LL * a[i] * nCk[j++]) % M;

    j = k;
    for (int i = n - k; i >= 0; --i)
        min_sum = (min_sum + 1LL * a[i] * nCk[j++]) % M;

    cout << (max_sum - min_sum + M) % M << '\n';
    // cout << max_sum << ' ' << min_sum << '\n';
    // for (int i = k; i <= n; ++i) cout << nCk[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}