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

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T>& a);

void solve() {
    int n;
    cin >> n;
    vvi g(n + 1);
    vi deg(n + 1, 0);

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    set<ii> q;
    for (int i = 1; i <= n; ++i) q.insert({deg[i], i});

    while (q.size() > 1) {
        int u, v, x;
        tie(x, u) = *q.begin();
        q.erase(q.begin());

        tie(x, v) = *q.begin();
        q.erase(q.begin());

        cout << "? " << u << ' ' << v << endl;
        cin >> x;
        if (x == -1) return;
        if (x == u) {
            cout << "! " << x << '\n';
            return;
        }
        if (x == v) {
            cout << "! " << x << '\n';
            return;
        }

        for (auto& p : g[u]) {
            if (!deg[p]) continue;
            q.erase({deg[p], p});
            deg[u]--;
            deg[p]--;
            q.insert({deg[p], p});
        }
        for (auto& p : g[v]) {
            if (!deg[p]) continue;
            q.erase({deg[p], p});
            deg[v]--;
            deg[p]--;
            q.insert({deg[p], p});
        }
    }
    int u, x;
    tie(x, u) = *q.begin();
    cout << "! " << u << '\n';
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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
void print_all(vector<T>& a) {
    for (auto i = a.begin(); i != a.end();) cout << *i << " \n"[++i == a.end()];
}