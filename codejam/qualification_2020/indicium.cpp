#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
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

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

int n;
vvi a;
vi b = {1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
vi x, y;

int cnt;
bool dfs(int p = 0) {
    cnt++;
    if (p == n * n) return true;
    if (a[x[p]][y[p]]) return dfs(p + 1);

    int t = rand() % 3197;
    for (int i = 0; i < n; ++i) {
        t = (t + 1) % n;
        bool ok = true;
        for (int j = 0; j < n; ++j)
            if (a[x[p]][j] == t + 1) {
                ok = false;
                break;
            }

        if (ok) {
            for (int j = 0; j < n; ++j)
                if (a[j][y[p]] == t + 1) {
                    ok = false;
                    break;
                }
        }

        if (ok) {
            a[x[p]][y[p]] = t + 1;
            if (dfs(p + 1)) return true;
            a[x[p]][y[p]] = 0;
        }
    }

    return false;
}
void solve() {
    n = 7;
    x.resize(n * n);
    y.resize(n * n);
    a.assign(n, vi(n));
    for (int i = 0; i < n * n; ++i) {
        x[i] = i / n;
        y[i] = i % n;
    }
    for (int i = 0; i < n; ++i) a[i][i] = b[i];

    write("before");
    write(dfs());
    write(cnt);
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);
    srand(time(NULL));

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}