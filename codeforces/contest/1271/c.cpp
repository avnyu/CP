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

int M = 1e9;

void apply(vector<ii> &a, ii s, int &res, int &rx, int &ry, int x, int y) {
    if (x < 0 || x > M) return;
    if (y < 0 || y > M) return;

    auto in = [](ii p1, ii p2, int x, int y) {
        int mnx = min(p1.fi, p2.fi);
        int mxx = max(p1.fi, p2.fi);
        int mny = min(p1.se, p2.se);
        int mxy = max(p1.se, p2.se);
        return mnx <= x && x <= mxx && mny <= y && y <= mxy;
    };

    int cnt = 0;
    for (auto &i : a) cnt += in(s, i, x, y);
    if (cnt > res) {
        res = cnt;
        rx = x;
        ry = y;
    }
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<ii> a(n);
    for (auto &i : a) cin >> i.fi >> i.se;

    int res = -1, rx, ry;

    apply(a, {x, y}, res, rx, ry, x - 1, y - 1);
    apply(a, {x, y}, res, rx, ry, x - 1, y);
    apply(a, {x, y}, res, rx, ry, x - 1, y + 1);
    apply(a, {x, y}, res, rx, ry, x, y - 1);
    apply(a, {x, y}, res, rx, ry, x, y + 1);
    apply(a, {x, y}, res, rx, ry, x + 1, y - 1);
    apply(a, {x, y}, res, rx, ry, x + 1, y);
    apply(a, {x, y}, res, rx, ry, x + 1, y + 1);

    cout << res << '\n';
    cout << rx << ' ' << ry << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    solve();

    return 0;
}