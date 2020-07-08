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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> rs(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            if ((i + j) % 2 == 0 || (i == n - 1 && j == m - 1))
                rs[i][j] = 'B';
            else
                rs[i][j] = 'W';
    }
    if (n % 2 == 0 && m % 2 == 0) rs[n - 1][m - 2] = 'B';
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cout << rs[i][j] << (j == m - 1 ? "\n" : "");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
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