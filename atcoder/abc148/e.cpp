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
    ll n;
    cin >> n;
    if (n & 1) {
        cout << "0\n";
        return;
    }
    n /= 10;
    ll x = 1, res = 0;
    while (x <= n) {
        res += n / x;
        x *= 10;
    }
    x = 5;
    while (x <= n) {
        res += n / x;
        x *= 5;
    }
    x = 10;
    while(x <= n){
        res -= n / x;
        x *= 10;
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