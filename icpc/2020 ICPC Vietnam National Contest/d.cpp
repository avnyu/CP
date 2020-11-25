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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 3e5 + 7;
vi up(N), down(N);
vvii g(N);

int dfs(int u) {
    ii bst = {0, 0};
    for (auto &e : g[u]) {
        int &v = e.fi, &w = e.se;
        int d = w + dfs(v);
        if (d > bst.fi) swap(d, bst.fi);
        if (d > bst.se) swap(d, bst.se);
    }
    down[u] = bst.fi + bst.se;
    return bst.fi;
}
bool solve(int T) {
    int n;
    cin >> n;
    for (int i = 1; i++ < n;) {
        int p, w;
        cin >> p >> w;
        g[p].push_back({i, w});
    }
    dfs(1);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

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