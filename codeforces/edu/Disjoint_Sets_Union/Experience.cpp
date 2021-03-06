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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 3e5 + 7;
vi par(N, -1), lz(N, 0);
vector<unordered_map<int, int>> in(N);

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    if (-par[u] < -par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    for (auto& i : in[v]) in[u][i.fi] = i.se + lz[v] - lz[u];
}
void add(int u, int v) { lz[u] += v; }
int get(int x) {
    int u = root(x);
    return in[u][x] + lz[u];
}
void solve(int T) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i++ < n;) in[i][i] = 0;
    for (; m--;) {
        string s;
        int u, v;
        cin >> s;
        if (s[0] == 'j') {
            cin >> u >> v;
            merge(u, v);
        } else if (s[0] == 'a') {
            cin >> u >> v;
            add(root(u), v);
        } else {
            cin >> u;
            print(get(u));
        }
    }
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