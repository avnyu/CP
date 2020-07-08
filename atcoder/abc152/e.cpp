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

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int M = 1e9 + 7, N = 1e6 + 1;

int fpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (1LL * res * x) % M;
        y >>= 1;
        x = (1LL * x * x) % M;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& i : a) cin >> i;

    vi chk(N), factl(N);
    vvi fact(N, vi(10));
    for (int i = 2; i < N; ++i) {
        if (!chk[i]) {
            int j = i;
            while (j < N) {
                chk[j] = 1;
                fact[j][factl[j]++] = i;
                j += i;
            }
        }
    }

    chk.assign(N, 0);
    for (auto& i : a) {
        for (int j = 0; j < factl[i]; ++j) {
            int cnt = 0, x = i, fi = fact[i][j];
            while (x % fi == 0) {
                x /= fi;
                cnt++;
            }
            chk[fi] = max(chk[fi], cnt);
        }
    }

    // for (int i = 2; i < N; ++i)
    //     if (chk[i]) cout << i << ' ' << chk[i] << '\n';

    int x = 1;
    for (int i = 2; i < N; ++i)
        if (chk[i]) x = (1LL * x * fpow(i, chk[i])) % M;
    int res = 0;
    for (auto& i : a) res = (res + (1LL * x * fpow(i, M - 2)) % M) % M;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}