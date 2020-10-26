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

void solve(int t) {
    int n;
    cin >> n;
    vi cnt(201);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int j = 0;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        while (!cnt[j]) j++;
        a[i] = j;
        cnt[j]--;
    }
    int res = 0;
    vector<vvi> dp(n, vvi(3, vi(4, 0)));
    dp[0][1][0] = dp[0][0][1] = dp[0][2][1] = 1;
    for (int i = 1; i < n; ++i)
        for (int j1 = 0; j1 < 3; ++j1)
            for (int j2 = 0; j2 < 3; ++j2)
                for (int c = 0; c < 3; ++c) {
                    int nc = c + (j2 != 1);
                    if (abs((a[i - 1] + j1 - 1) - (a[i] + j2 - 1)) <= 2)
                        dp[i][j2][nc] =
                            max(dp[i][j2][nc], dp[i - 1][j1][c] + 1);
                    else
                        dp[i][j2][nc] = 1;
                    if (nc < 3) res = max(res, dp[i][j2][nc]);
                }
    cout << "Case " << t << ": " << res << '\n';
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