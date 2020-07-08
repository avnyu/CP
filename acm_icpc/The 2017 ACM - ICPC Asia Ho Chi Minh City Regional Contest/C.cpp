#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int n;
    cin >> n;
    vector<int> d(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> d[i];

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (d[j]) {
                p[i] = j;
                d[i]--;
                d[j]--;
                break;
            }
        }
    }

    partial_sum(d.begin(), d.end(), d.begin());
    cout << (d.back() ? "NO\n" : "YES\n");

    return 0;
}