#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

map<string, int> s;
vector<string> a(10);

void solve() {
    int n;
    cin >> n;
    vector<int> pass(n, 0);

    s.clear();
    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (s[a[i]] == 0) pass[i] = 1;
        s[a[i]] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (pass[i]) continue;
        if (s[a[i]] == 1) {
            k++;
            for (int j = 0; j < 10; ++j) {
                a[i][0] = (a[i][0] - 48 + 1) % 10 + 48;
                if (s[a[i]] == 0) break;
            }
        }
        s[a[i]] = 1;
    }
    cout << k << '\n';
    for (int i = 0; i < n; ++i) cout << a[i] << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}