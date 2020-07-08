#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

auto query(int i, int j) {
    cout << "? " << i << ' ' << j << '\n';
    cout.flush();
    char c;
    cin >> c;
    return c == '<';
}

void add(vector<int>& a, int v) {
    for (int i = 0; i < a.size(); ++i)
        if (query(v, a[i])) {
            a.emplace(a.begin() + i, v);
            return;
        };
    a.emplace_back(v);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v1, v2;
    for (int i = 0; i < 2; ++i) add(v1, i + 1);
    for (int i = 2; i < n + 1; ++i) add(v2, i + 1);

    for (int i = 1; i < n; ++i) {
        if (query(v1.front(), v2.front())) {
            v1.erase(v1.begin());
            add(v1, i + n + 1);
        } else {
            v2.erase(v2.begin());
            add(v2, i + n + 1);
        }
    }

    query(v1.front(), v2.front());

    cout << "!\n";
    cout.flush();
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}