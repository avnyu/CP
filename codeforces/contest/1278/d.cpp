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

int n, m, N = 5e5 + 7;
vector<int> par(N, -1);

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    par[u] += par[v];
    par[v] = u;
}

void solve() {
    cin >> n;
    stack<int> s1, s2;
    vector<ii> v;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, i + 1});
        v.push_back({y, -i - 1});
    }
    sort(v.begin(), v.end());
    for (auto& p : v) {
        int x = p.fi, i = p.se;
        if (i > 0)
            s1.push(i);
        else {
            while (!s1.empty() && s1.top() != -i) {
                s2.push(s1.top());
                merge(s1.top(), -i);
                m++;
                if (m >= n) {
                    cout << "NO\n";
                    return;
                }
                s1.pop();
            }
            s1.pop();
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    if (m != n - 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (par[root(i)] != -n) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}