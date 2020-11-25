#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(v)        \
    for (auto &i : v) \
        cout << (i < 10 ? " " : "") << i << " \n"[&i == &v.back()];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const ll M = 1e18;
vl len_up, len_down, dia_up, dia_down;
vvii g;

ll get_len_down(int u = 1) {
    len_down[u] = 0;
    for (int i = 0; i < int(g[u].size()); ++i) {
        int &v = g[u][i].fi, &w = g[u][i].se;
        len_down[u] = max(len_down[u], get_len_down(v) + w);
    }
    return len_down[u];
}
void get_len_up(int u = 1) {
    priority_queue<ll> pq;
    pq.push(len_up[u]);

    for (int i = 0; i < int(g[u].size()); ++i) {
        int &v = g[u][i].fi, &w = g[u][i].se;
        pq.push(len_down[v] + w);
    }

    for (int i = 0; i < int(g[u].size()); ++i) {
        int &v = g[u][i].fi, &w = g[u][i].se;
        ll d = len_down[v] + w;

        if (d == pq.top()) {
            pq.pop();
            d = -d;
        }

        len_up[v] = pq.top() + w;

        if (d < 0) pq.push(-d);

        get_len_up(v);
    }
}
void get_dia_down(int u = 1) {
    dia_down[u] = 0;

    vl bst(2, 0);
    for (int i = 0; i < int(g[u].size()); ++i) {
        int &v = g[u][i].fi, &w = g[u][i].se;
        ll d = len_down[v] + w;
        for (int j = 0; j < 2; ++j)
            if (bst[j] < d) swap(bst[j], d);

        get_dia_down(v);

        dia_down[u] = max(dia_down[u], dia_down[v]);
    }
    dia_down[u] = max(dia_down[u], bst[0] + bst[1]);
}
void get_dia_up(int u = 1) {
    priority_queue<ll> pq;

    for (int i = 0; i < int(g[u].size()); ++i) {
        int &v = g[u][i].fi, &w = g[u][i].se;
        pq.push(dia_down[v]);
    }
    pq.push(0);
    for (int i = 0; i < int(g[u].size()); ++i) {
        int &v = g[u][i].fi, &w = g[u][i].se;
        ll diav = dia_down[v];
        if (diav == pq.top()) {
            diav = -diav;
            pq.pop();
        }
        dia_up[v] = max(dia_up[u], pq.top());
        if (diav < 0) pq.push(-diav);
    }

    while (pq.size()) pq.pop();
    pq.push(0);
    pq.push(0);
    pq.push(len_up[u]);

    for (int i = 0; i < int(g[u].size()); ++i) {
        int &v = g[u][i].fi, &w = g[u][i].se;
        pq.push(len_down[v] + w);
    }

    vl bst(2);
    for (int i = 0; i < int(g[u].size()); ++i) {
        int &v = g[u][i].fi, &w = g[u][i].se;
        ll d = len_down[v] + w;

        for (int j = 0; j < 2; ++j) {
            if (d == pq.top()) {
                pq.pop();
                d = -d;
            }
            bst[j] = pq.top();
            pq.pop();
        }

        dia_up[v] = max(dia_up[v], bst[0] + bst[1]);

        if (d < 0) pq.push(-d);
        for (int j = 0; j < 2; ++j) pq.push(bst[j]);

        get_dia_up(v);
    }
}
bool solve(int T) {
    int n;
    cin >> n;

    if (n == 0) return false;

    g.clear();
    g.assign(n + 1, vii());
    len_up.assign(n + 1, 0);
    len_down.assign(n + 1, 0);
    dia_up.assign(n + 1, 0);
    dia_down.assign(n + 1, 0);

    for (int i = 1; i++ < n;) {
        int p, w;
        cin >> p >> w;
        g[p].push_back({i, w});
    }

    get_len_down();
    get_len_up();
    get_dia_down();
    get_dia_up();

    // prt(len_down);
    // prt(len_up);
    // prt(dia_down);
    // prt(dia_up);

    ll res = M;
    for (int i = 0; i++ < n;) res = min(res, abs(dia_down[i] - dia_up[i]));

    print(res);
    return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int t = 1;
    // cin >> t;
    // for (int i = 0; i++ < t;) solve(i);

    while (1)
        if (!solve(0)) break;

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}