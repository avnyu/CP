#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <typeinfo>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 1e5;
vector<int> par(N << 2, -1);

int root(int u) { return par[u] < 0 ? u : (par[u] = root(par[u])); }
bool merge(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return false;
    par[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int q;
    cin >> q;
    vector<lli> r(q), c(q);
    vector<tuple<lli, lli, string, string>> query(q);

    for (int i = 0; i < q; ++i) {
        lli x, y;
        string ai, bi;
        cin >> x >> y >> ai >> bi;

        query[i] = {x, y, ai, bi};
        r[i] = x;
        c[i] = y;
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    bool no = false;
    for (int i = 0; i < q; ++i) {
        if (no) {
            cout << "No\n";
            continue;
        }
        lli x, y;
        string ai, bi, ci;
        tie(x, y, ai, bi) = query[i];

        x = lower_bound(r.begin(), r.end(), x) - r.begin();
        y = lower_bound(c.begin(), c.end(), y) - c.begin() + N + N;

        if (ai == bi) {
            merge(N + x, N + y);
            merge(x, y);
            // cout << "merge " << N + x << ' ' << N + y << " - " << x << ' ' <<
            // y
            //      << '\n';
        } else {
            merge(N + x, y);
            merge(x, N + y);
            // cout << "merge " << N + x << ' ' << y << " - " << x << ' ' << N +
            // y
            //      << '\n';
        }

        no |= (root(x) == root(x + N));
        no |= (root(y) == root(y + N));
        // cout << root(x) << ' ' << root(x + N) << ' ' << root(y) << ' ' <<
        // root(y + N) << '\n';

        cout << (no ? "No\n" : "Yes\n");
    }

    return 0;
}