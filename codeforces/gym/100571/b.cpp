#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <typeinfo>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int N = 1e5 + 7, M = 1e9 + 7;
    vector<int> f(N), x(N), add(N);

    int n, q, f1, f2, a, b;
    cin >> n >> q >> f1 >> f2 >> a >> b;
    for (int i = 1; i <= n; ++i) cin >> x[i];

    f[0] = f1, f[1] = f2;
    for (int i = 2; i < N; ++i)
        f[i] = (1LL * a * f[i - 2] + 1LL * b * f[i - 1]) % M;

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        if (l == r) {
            x[l] = (x[l] + f[0]) % M;
            continue;
        }

        add[l] = (add[l] + f[0]) % M;
        add[l + 1] = (add[l + 1] + f[1]) % M;
        add[l + 1] = (add[l + 1] + M - (1LL * b * f[0]) % M) % M;

        add[r + 1] = (add[r + 1] + M - f[r + 1 - l]) % M;
        add[r + 2] = (add[r + 2] + M - f[r + 2 - l]) % M;
        add[r + 2] = (add[r + 2] + (1LL * b * f[r + 1 - l]) % M) % M;
    }

    // for (int i = 1; i <= n; ++i) cerr << add[i] << " \n"[i == n];
    // for (int i = 1; i <= n; ++i) cerr << x[i] << " \n"[i == n];

    for (int i = 2; i < N; ++i)
        add[i] =
            (1LL * add[i] + 1LL * a * add[i - 2] + 1LL * b * add[i - 1]) % M;

    for (int i = 1; i <= n; ++i) x[i] = (x[i] + add[i]) % M;

    // for (int i = 0; i <= n; ++i) cerr << f[i] << " \n"[i == n];
    // for (int i = 1; i <= n; ++i) cerr << add[i] << " \n"[i == n];
    for (int i = 1; i <= n; ++i) cout << x[i] << " \n"[i == n];

    return 0;
}