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
    ll x;
    cin >> x;
    if (x < 14) {
        cout << "NO\n";
        return;
    }
    if (x % 14 == 0) {
        cout << "NO\n";
        return;
    }
    if (x % 14 > 6) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}