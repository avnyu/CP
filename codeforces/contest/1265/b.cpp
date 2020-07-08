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
    int n;
    cin >> n;
    vector<ii> p;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p.push_back({x, i});
    }
    sort(p.begin(), p.end());
    int mx = p[0].se, mn = p[0].se;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, p[i].se), mn = min(mn, p[i].se);
        cout << (mx - mn == i ? '1' : '0') << (i != n - 1 ? "" : "\n");
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}