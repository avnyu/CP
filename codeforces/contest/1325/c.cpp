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

const int N = 1e5 + 7;
int n;
vi deg(N), res(N, -1);
vector<vector<ii>> g(N);

void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].push_back({v, i});
        g[v].push_back({u, i});

        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; ++i)
        if (deg[i] >= 3) {
            for (int j = 0; j < 3; ++j) res[g[i][j].se] = j;

            int k = 3;
            for (int j = 1; j < n; ++j)
                cout << (res[j] != -1 ? res[j] : k++) << " \n"[j == n - 1];

            return;
        }

    for (int i = 1; i < n; ++i) cout << i - 1 << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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