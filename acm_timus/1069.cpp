#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1 << 13;

vector<pair<int, int>> pruefer(vector<int>& p) {
    priority_queue<int> pq;
    vector<pair<int, int>> res;
    int n = p.size() + 2;
    vector<int> a(n, 0);

    for (auto& i : p) a[i]++;

    for (int i = 1; i < n; ++i)
        if (!a[i]) pq.push(-i);

    for (int i = 0; i < n - 2; ++i) {
        int u = -pq.top();
        pq.pop();

        int v = p[i];
        if (!--a[v]) pq.push(-v);

        res.push_back({u, v});
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("in", "r", stdin);

    vector<int> p;

    int x, n;
    while (cin >> x) p.emplace_back(x);
    // p.emplace_back(n);
    n = p.size() + 2;

    vector<pair<int, int>> a = pruefer(p);
    // for (auto& i : a) cout << i.first << ' ' << i.second << '\n';

    vector<vector<int>> g(n);
    for (auto& i : a)
        g[i.first].emplace_back(i.second), g[i.second].emplace_back(i.first);

    for (int i = 1; i < n; ++i) {
        cout << i << ": ";
        sort(g[i].begin(), g[i].end());
        for (auto& j : g[i]) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}