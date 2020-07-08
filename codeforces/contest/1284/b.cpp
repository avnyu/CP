#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
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

void solve() {
    int n, m = 0, asc = 0;
    cin >> n;
    vi head(n), tail(n);
    for (int i = 0; i < n; ++i) {
        int l, prv, h;
        cin >> l >> h;
        prv = h;

        bool chk = false;
        for (int i = 1; i < l; ++i) {
            int nxt;
            cin >> nxt;
            chk |= (nxt > prv);
            prv = nxt;
        }

        if (chk)
            asc++;
        else {
            head[m] = h;
            tail[m] = prv;
            m++;
        }
    }

    ll res = 2LL * asc * (n - asc) + 1LL * asc * asc;
    sort(tail.begin(), tail.begin() + m);

    for (int i = 0; i < m; ++i) {
        int pos = lower_bound(tail.begin(), tail.begin() + m, head[i]) - tail.begin();
        res += pos;
    }

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