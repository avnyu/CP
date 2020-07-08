#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int N = 1e6 + 7, res = 0;
    for (int i = 0; i < N; ++i) {
        if (i > a || i > d) continue;
        int j = min(d - i, min(b, c));
        res = max(res, i * e + j * f);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    solve();

    return 0;
}