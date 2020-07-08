#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    vector<int> ans(1, 0);

    int x = 1;
    while (x <= n) {
        ans.push_back(n / x);
        x = n / (n / x) + 1;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto& i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}