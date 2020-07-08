#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using rbtree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T> &a);

const int N = 1e5 + 7;
vi res(N), in(N), par(N), a(N);
vvi query(N, vi(4));
unordered_map<int, vi> height;
rbtree<int> lef, rig;

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
int merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return u;
    if (v < u) swap(u, v);
    par[u] += par[v];
    return par[v] = u;
}

int count(int l, int r) {
    return lef.order_of_key(r + 1) - rig.order_of_key(l);
}
void update(int p) {
    if (in[p + 1]) {
        int r = root(p + 1);
        lef.erase(r);
        rig.erase(r - par[r] - 1);
        p = merge(p, r);
    }
    if (in[p - 1]) {
        int l = root(p - 1);
        lef.erase(l);
        rig.erase(l - par[l] - 1);
        p = merge(l, p);
    }
    lef.insert(p);
    rig.insert(p - par[p] - 1);
}

void solve() {
    int n, q;
    cin >> n >> q;

    a.assign(n, -1);
    res.assign(q, -1);
    query.assign(q, vi(4));
    height.clear();

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        height[a[i]].emplace_back(i + 1);
    }

    for (int i = 0; i < q; ++i) {
        int &l = query[i][0], &r = query[i][1];
        int &y = query[i][2], &j = query[i][3];
        cin >> l >> r >> y;
        j = i;
    }

    sort(all(query), [](vi &a, vi &b) { return a[2] < b[2]; });
    sort(all(a));
    uni(a);

    // number of group with smaller height
    in.assign(n + 2, 0), par.assign(n + 2, -1);
    lef.clear(), rig.clear();
    int t = 0;
    for (int i = 0; i < q; ++i) {
        int &l = query[i][0], &r = query[i][1];
        int &y = query[i][2], &j = query[i][3];
        while (t < a.size() && a[t] < y) {
            for (auto &p : height[a[t]]) {
                update(p);
                in[p] = 1;
            }
            t++;
        }
        res[j] += count(l, r);
        // write("smaller", j, count(l, r));
    }

    // number of group with larger height
    in.assign(n + 2, 0), par.assign(n + 2, -1);
    lef.clear(), rig.clear();
    t = a.size() - 1;
    for (int i = q; i--;) {
        int &l = query[i][0], &r = query[i][1];
        int &y = query[i][2], &j = query[i][3];
        while (t >= 0 && a[t] > y) {
            for (auto &p : height[a[t]]) {
                in[p] = 1;
                update(p);
            }
            t--;
        }
        res[j] += count(l, r);
        // write("larger ", j, count(l, r));
    }

    // number of point with equal height
    t = 0;
    lef.clear(), rig.clear();
    for (int i = 0; i < q; ++i) {
        int &l = query[i][0], &r = query[i][1];
        int &y = query[i][2], &j = query[i][3];

        if (i && y != query[i - 1][2]) {
            lef.clear();
            rig.clear();
        }

        while (t < a.size() && a[t] < y) t++;
        if (t < a.size() && a[t] == y)
            for (auto &p : height[y]) lef.insert(p), rig.insert(p);

        res[j] += count(l, r);
        // write("equal  ", j, count(l, r));
    }

    for (int i = 0; i < q; ++i) cout << res[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T> &a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}