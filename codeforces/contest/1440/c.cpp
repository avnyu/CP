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

#define vvc vector<vector<char>>

void make_change(vvc& a, vvi& res, ii x, ii y, ii z) {
    a[x.fi][x.se] = a[x.fi][x.se] == '0' ? '1' : '0';
    a[y.fi][y.se] = a[y.fi][y.se] == '0' ? '1' : '0';
    a[z.fi][z.se] = a[z.fi][z.se] == '0' ? '1' : '0';
    res.push_back(
        vi{x.fi + 1, x.se + 1, y.fi + 1, y.se + 1, z.fi + 1, z.se + 1});
}
void fix(vvc& a, vvi& res, int x, int y) {
    vii p0, p1;
    for (int i = x; i < x + 2; ++i)
        for (int j = y; j < y + 2; ++j)
            if (a[i][j] == '0')
                p0.push_back(ii{i, j});
            else
                p1.push_back(ii{i, j});
    if (p1.size() == 4) {
        make_change(a, res, p1[0], p1[1], p1[2]);
        fix(a, res, x, y);
    } else if (p1.size() == 3) {
        make_change(a, res, p1[0], p1[1], p1[2]);
        fix(a, res, x, y);
    } else if (p1.size() == 2) {
        make_change(a, res, p1[0], p0[0], p0[1]);
        fix(a, res, x, y);
    } else if (p1.size() == 1) {
        make_change(a, res, p1[0], p0[0], p0[1]);
        fix(a, res, x, y);
    }
}
void push_down(vvc& a, vvi& res, int i, int j) {
    vii need;
    if (a[i][j] == '1') need.push_back(ii{i, j});
    if (a[i][j + 1] == '1') need.push_back(ii{i, j + 1});
    if (need.empty()) return;
    need.push_back(ii{i + 1, j});
    if (need.size() < 3) need.push_back(ii{i + 1, j + 1});
    make_change(a, res, need[0], need[1], need[2]);
}
void push_left(vvc& a, vvi& res, int i, int j) {
    vii need;
    if (a[i][j] == '1') need.push_back(ii{i, j});
    if (a[i + 1][j] == '1') need.push_back(ii{i + 1, j});
    if (need.empty()) return;
    need.push_back(ii{i, j + 1});
    if (need.size() < 3) need.push_back(ii{i + 1, j + 1});
    make_change(a, res, need[0], need[1], need[2]);
}
void solve(int T) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (auto& i : a)
        for (auto& j : i) cin >> j;

    vvi res;
    if (n & 1) {
        for (int j = 0; j < m - 1; ++j) push_down(a, res, 0, j);
    }
    if (m & 1) {
        for (int i = 0 + (n & 1); i < n - 1; ++i) push_left(a, res, i, 0);
    }
    for (int i = 0 + (n & 1); i < n - 1; i += 2)
        for (int j = 0 + (m & 1); j < m - 1; j += 2) fix(a, res, i, j);

    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < m; ++j) cout << a[i][j] << " \n"[j == m - 1];
    cout << res.size() << '\n';
    for (auto& i : res)
        for (int j = 0; j < 6; ++j) cout << i[j] << " \n"[j == 5];
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
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