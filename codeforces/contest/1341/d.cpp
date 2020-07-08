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

vector<string> code = {"1110111", "0010010", "1011101", "1011011", "0111010",
                       "1101011", "1101111", "1010010", "1111111", "1111011"};
int up_cost(string &x, int y) {
    int rs = 0;
    for (int i = 0; i < 7; ++i) {
        if (x[i] == '1' && code[y][i] == '0') return -1;
        rs += x[i] != code[y][i];
    }
    return rs;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vvi dp(n + 1, vi(k + 1, -1));
    dp[n][0] = 0;

    for (int i = n; i--;) {
        for (int j = 0; j < 10; ++j) {
            int uc = up_cost(a[i], j);
            if (uc == -1) continue;

            for (int t = 0; t + uc <= k; ++t)
                if (dp[i + 1][t] != -1) dp[i][t + uc] = j;
        }
    }
    if (dp[0][k] == -1) {
        write(-1);
        return;
    }
    int cur = k;
    for (int i = 0; i < n; ++i) {
        cout << dp[i][cur];
        cur -= up_cost(a[i], dp[i][cur]);
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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