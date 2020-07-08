#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
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

const int M = 998244353;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

const int N = 2e5 + 1;
vi par(N, -1);

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
int merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return u;
    if (u > v) swap(u, v);
    par[u] += par[v];
    return par[v] = u;
}

void solve() {
    int n;
    cin >> n;
    vector<ii> a(n);
    vi nxt(n);
    for (int i = 0; i < n; ++i) cin >> a[i].fi >> a[i].se;
    sort(all(a));

    stack<int> in;
    for (int i = n; i--;) {
        int x = upper_bound(all(a), ii{a[i].fi + a[i].se, 0}) - a.begin() - 1;

        if (i == x) {
            nxt[i] = i + 1;
            in.push(i);
            continue;
        }

        while (!in.empty()) {
            int f = in.top();

            if (f > x) break;

            in.pop();
            merge(i, f);
        }
        nxt[i] = i - par[i];
        in.push(i);
    }

    vi dp(n + 1, 1);
    for (int i = n; i--;) dp[i] = (dp[nxt[i]] + dp[i + 1]) % M;
    cout << dp[0] << '\n';
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