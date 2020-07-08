#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
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

const int N = 1e5 + 1;
int n, m, k;
vvi g(N);
vi tpar(N, -1);
vi hgt(N, 0);
set<ii> e;

void dfs(int u, int p, int h = 1) {
    if (tpar[u] != -1) return;
    if (p) {
        e.erase(ii{p, u});
        e.erase(ii{u, p});
    }
    tpar[u] = p;
    hgt[u] = h;
    for (auto& v : g[u])
        if (v <= k) dfs(v, u, h + 1);
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        e.insert({u, v});
    }
    dfs(1, 0);
    for (int i = 0; i++ < k;)
        if (tpar[i] == -1) {
            write("sdf");
            return;
        }
    for (auto& ei : e) {
        int i, j;
        tie(i, j) = ei;
        if (i <= k && j <= k) {
            if (hgt[i] > hgt[j]) swap(i, j);

            vi lef = {i}, rig = {j};
            while (hgt[j] > hgt[i]) {
                j = tpar[j];
                rig.push_back(j);
            }
            while (i != j) {
                i = tpar[i];
                j = tpar[j];
                lef.push_back(i);
                rig.push_back(j);
            }
            write(2);
            write(lef.size() + rig.size() - 1);
            for (auto& i : lef) cout << i << ' ';
            for (int j = rig.size() - 1; j--;) cout << rig[j] << " \n"[!j];
            // for (int i = 1; i <= n; ++i) cout << tpar[i] << " \n"[i ==
            // n];
            return;
        }
    }
    write(1);
    vvi cnt(2);
    for (int i = 0; i++ < k;) cnt[hgt[i] & 1].push_back(i);
    if (cnt[0].size() < cnt[1].size()) swap(cnt[0], cnt[1]);
    for (int i = 0; i < (k + 1) / 2; ++i)
        cout << cnt[0][i] << " \n"[i == (k + 1) / 2 - 1];

    // for (int i = 1; i <= n; ++i) cout << tpar[i] << " \n"[i == n];
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
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}
