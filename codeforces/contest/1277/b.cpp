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
    map<int, int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int cnt = 0;
        while (x % 2 == 0) {
            x /= 2;
            cnt++;
        }

        a[x] = max(a[x], cnt);
    }
    int res = 0;
    for (auto& i : a) res += i.second;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}