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

const int N = 107;
const int M = 1e9 + 7;
int n, m, k;
vii b(N);
vvi pass(N, vi(N)), dp(N, vi(4, M)), dis(N, vi(N));
vector<ii> step = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<char>> a(N, vector<char>(N, '#'));

void reset() {
    for (int i = 0; i < n + 2; ++i)
        for (int j = 0; j < m + 2; ++j) {
            pass[i][j] = a[i][j] == '#' ? 1 : 0;
            // dis[i][j] = M;
        }
}
int distance(ii tu, ii tv) {
    if (a[tu.fi][tu.se] == '#' || a[tv.fi][tv.se] == '#') return M;

    reset();
    queue<ii> q;

    q.push(tu);
    dis[tu.fi][tu.se] = 0;
    pass[tu.fi][tu.se] = 1;

    while (!q.empty()) {
        ii u = q.front();
        q.pop();

        if (u == tv) break;

        for (auto& st : step) {
            ii v = {u.fi + st.fi, u.se + st.se};

            if (pass[v.fi][v.se]) continue;

            q.push(v);
            dis[v.fi][v.se] = dis[u.fi][u.se] + 1;
            pass[v.fi][v.se] = 1;
        }
    }
    return dis[tv.fi][tv.se];
    // return M;
}
void solve(int T) {
    cin >> n >> m >> k;
    ii s, f;
    for (int i = 0; i++ < n;)
        for (int j = 0; j++ < m;) {
            cin >> a[i][j];
            if (a[i][j] == 'S') s = ii{i, j};
            if (a[i][j] == 'F') f = ii{i, j};
        }
    for (int i = 0; i < k; ++i) cin >> b[i].fi >> b[i].se;

    for (int i = 0; i < 4; ++i) dp[0][i] = 0;

    for (int i = 0; i < k + 1; ++i) {
        for (int j1 = 0; j1 < 4; ++j1)
            for (int j2 = 0; j2 < 4; ++j2) {
                ii u = i != 0 ? ii{b[i - 1].fi + step[j1].fi,
                                   b[i - 1].se + step[j1].se}
                              : s;
                ii v = i != k ? ii{b[i].fi + step[j2].fi, b[i].se + step[j2].se}
                              : f;

                dp[i + 1][j2] = min(dp[i + 1][j2], dp[i][j1] + distance(u, v));
            }
    }
    cout << (dp[k + 1][0] == M ? -1 : dp[k + 1][0]) << '\n';

    // for (int i = 0; i < n + 2; ++i)
    //     for (int j = 0; j < m + 2; ++j) cout << a[i][j] << " \n"[j == m + 1];

    // for (int i = 0; i < k + 2; ++i)
    //     for (int j = 0; j < 4; ++j) cout << dp[i][j] << " \n"[j == 3];

    // print(distance(ii{1, 1}, ii{1, 2}));
    // print(s.fi, s.se);
    // print(f.fi, f.se);
    // print(n, m, k);

    print(distance(ii{1, 2}, ii{3, 1}));
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
        cout << x << endl;
    }
}