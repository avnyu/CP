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
    int n, N = 2e5 + 7;
    cin >> n;
    int cnt = 0, iy = 1;
    vector<string> y(N, "");
    for (int i = 0; i < N; ++i) y[i] = to_string(i);

    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        if (x != y[iy])
            cnt++;
        else
            iy++;
    }
    cout << (cnt == n ? -1 : cnt) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}