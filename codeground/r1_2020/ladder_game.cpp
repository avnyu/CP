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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int test_case) {
    int n, k, m, ans = 0;
    const int M = 1e9 + 7;
    cin >> n >> k >> m;
    vvi dp(n + 1, vi(n + 1, M));
    vi dpix(n + 1), dpiy(n + 1);
    for (int i = n + 1; i--;) dp[i][i] = 0;
    for (int i = k; i--;) {
        int x, y;
        cin >> x >> y;
        for (int i = n + 1; i--;) {
            dpix[i] = dp[i][x];
            dpiy[i] = dp[i][y];
        }

        for (int i = n + 1; i--;) {
            dp[i][x] = min(dpiy[i], dpix[i] + 1);
            dp[i][y] = min(dpix[i], dpiy[i] + 1);
        }
    }
    for (int i = m; i--;) {
        int x, y;
        cin >> x >> y;
        ans += dp[x][y] == M ? -1 : dp[x][y];
    }

    cout << "Case #" << test_case << '\n';
    print(ans);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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