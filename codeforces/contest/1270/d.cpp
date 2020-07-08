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
    int n, k;
    cin >> n >> k;

    auto query = [](int k, int r) {
        ii res;
        cout << '?';
        for (int i = 1; i <= k; ++i)
            if (i != r) cout << ' ' << i;
        cout << endl;
        cin >> res.fi >> res.se;
        return res;
    };

    map<int, int> a;
    for (int i = 1; i <= k + 1; ++i) {
        ii x = query(k + 1, i);
        a[x.se]++;
    }

    cout << "! " << a.rbegin()->se << endl;
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}