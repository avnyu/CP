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
    int n, x, y, t;
    cin >> n >> x >> y;
    int win = 0;
    for (int i = 0; i < x; ++i) {
        cin >> t;
        if (t == n) win = 1;
    }
    for (int i = 0; i < y; ++i) {
        cin >> t;
        if (t == n) win = 2;
    }
    cout << (win == 1 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}