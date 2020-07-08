#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>  // Including tree_order_statistics_node_update
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, m;
    vector<pair<int, int>> add;
    vector<int> res, a;
    vector<tuple<int, int, int>> query;
    ordered_set<int> rb;

    cin >> n;
    a.resize(n);
    add.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        add[i] = {a[i], -i};
    }
    sort(add.rbegin(), add.rend());

    cin >> m;
    query.resize(m);
    res.resize(m);

    for (int i = 0; i < m; ++i) {
        int k, p;
        cin >> k >> p;
        query[i] = {k, p, i};
    }
    sort(query.begin(), query.end());

    int siz = 0;
    for (auto& qi : query) {
        int k, p, i;
        tie(k, p, i) = qi;
        while (siz < k) rb.insert(-add[siz++].second);
        res[i] = *rb.find_by_order(p - 1);
    }

    for (int i = 0; i < m; ++i) cout << a[res[i]] << "\n";

    return 0;
}