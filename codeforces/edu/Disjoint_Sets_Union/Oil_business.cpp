#include <bits/stdc++.h>

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
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1e5 + 7;
vi par(N, -1);
int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    par[u] += par[v];
    par[v] = u;
}
void solve(int T) {
    int n, k;
    ll s;
    cin >> n >> k >> s;
    vvi e(k, vi(4));
    for (int i = 0; i++ < k;) {
        for (int j = 0; j < 3; ++j) cin >> e[i - 1][j];
        e[i - 1][3] = i;
    }

    sort(e.begin(), e.end(), [&](vi& a, vi& b) { return a[2] > b[2]; });
    for (auto& i : e) {
        int &u = i[0], &v = i[1], &w = i[2];
        if (root(u) != root(v)) {
            merge(u, v);
            u = 0;
        }
    }
    sort(e.begin(), e.end(), [&](vi& a, vi& b) { return a[2] < b[2]; });
    vi res;
    for (auto& i : e) {
        int &u = i[0], &v = i[1], &w = i[2];
        if (u && s - w >= 0) {
            s -= w;
            res.push_back(i[3]);
        }
    }
    print(res.size());
    prt(res);
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