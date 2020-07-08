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
    vector<int> a(n + n, 0);
    vector<int> lef(1, 0), rig(1, 0);
    for (auto& i : a) {
        cin >> i;
        if (i == 2) i = -1;
    }
    for (int i = 0; i < n; ++i) {
        lef.push_back(a[i]);
        rig.push_back(a[n + n - i - 1]);
    }
    partial_sum(lef.begin(), lef.end(), lef.begin());
    partial_sum(rig.begin(), rig.end(), rig.begin());

    int N = 1e5 + 7;
    vector<int> rig_index(N + N, -1);
    for (int i = 0; i <= n; ++i) rig_index[rig[i] + N] = max(rig_index[rig[i] + N], i);

    int res = N + N;
    for (int i = 0; i <= n; ++i) {
        int x = rig_index[-lef[i] + N];
        if (x != -1) res = min(res, n + n - i - x);
    }

    // for (int i = 0; i <= n; ++i) cout << lef[i] << " \n"[i == n];
    // for (int i = 0; i <= n; ++i) cout << rig[i] << " \n"[i == n];
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}