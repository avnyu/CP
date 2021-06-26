#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(u, v) \
    for (auto x = u; x != v;) cout << (*x) << " \n"[++x == v];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

typedef vector<double> vd;

void apply(vd &a, vd &b, int p) {
    double u = a[p];
    double v = a[p + 1];
    a[p] = min(u, (u + v - b[p]) / 2);
    a[p + 1] = max(v, (u + v + b[p]) / 2);
}
void test() {
    vd a = {3, 2, 100};
    vd b = {0, 0};

    prt(a.begin(), a.end());
    prt(b.begin(), b.end());

    srand(time(NULL));
    for (int i = 0; i < 10000; ++i) apply(a, b, rand() % 2);

    prt(a.begin(), a.end());
}
void solve() {
    const int M = 1e9 + 7;
    int n;
    cin >> n;
    vi c(n), b(n - 1);
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];
    int q, u;
    cin >> q >> u;

    vi a(n);
    a[0] = u;
    for (int i = 0; i < n - 1; ++i) a[i + 1] = a[i] + b[i];
    int sum = 0;
    for (int i = 0; i < n; ++i) sum = (sum + a[i]) % M;

    const int N = 101;
    const int V = N * N;

    vvi dp(N, vi(V));
    for (int v = max(0, u); v <= c[0]; ++v) {
        int req = 
    }

    vi tmp(V);
    for (int i = 1; i < n; ++i) {
        for (int cur = 0; cur < V; ++cur) tmp[cur] = 0;

        for (int last = 0; last < N; ++last)
            for (int cur = 0; cur < V; ++cur) {
                tmp[cur] = (tmp[cur] + dp[last][cur]) % M;
                dp[last][cur] = 0;
            }

        for (int last = 0; last <= c[i]; ++last)
            for (int cur = 0; cur < V; ++cur) {
                int next = cur + last < V ? cur + last : V - 1;
                dp[last][next] = (dp[last][next] + tmp[cur]) % M;
            }
    }

    int res = 0;
    for (int last = 0; last < N; ++last)
        for (int cur = 0; cur < V; ++cur) {
            int req = sum + (last > a[n - 1] ? last - a[n - 1] : 0);
            if (dp[last][cur] && cur >= req) {
                res = (res + dp[last][cur]) % M;
                // print(last, cur, dp[last][cur]);
            }
        }

    // print(sum);
    // prt(a.begin(), a.end());
    // for (int i = 0; i < 6; ++i) prt(dp[i].begin(), dp[i].begin() + 10);

    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve();
    // test();

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