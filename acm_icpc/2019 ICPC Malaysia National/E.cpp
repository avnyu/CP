#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool solve() {
    int t, n;
    cin >> t;
    if (t == 0) return false;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp(t + 1, 0);
    vector<int> prv(t + 1, -1);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = t - a[i]; j >= 0; --j) {
            if (dp[j] && !dp[j + a[i]]) {
                dp[j + a[i]] = 1;
                prv[j + a[i]] = j;
            }
        }
    }

    for (int i = t; i >= 0; --i) {
        if (dp[i]) {
            int s = i;
            vector<int> res;
            while (1) {
                res.emplace_back(i - prv[i]);
                i = prv[i];
                if (prv[i] == -1) break;
            }

            for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
            cout << s << '\n';
        }
    }
    return true;
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    while (solve())
        ;

    return 0;
}