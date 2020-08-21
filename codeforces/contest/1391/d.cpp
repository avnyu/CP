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

bool chkbit(int x, int p) { return x & 1 << p; }
int diff(int x, int y) {
    int res = 0;
    for (int i = 0; i < 3; ++i)
        if (chkbit(y, i) && !chkbit(x, i))
            res++;
        else if (!chkbit(y, i) && chkbit(x, i))
            res++;
    return res;
};
bool test(int x, int y, int m) {
    int cnt0 = chkbit(x, 0) + chkbit(x, 1) + chkbit(y, 0) + chkbit(y, 1);
    int cnt1 = chkbit(x, 2) + chkbit(x, 1) + chkbit(y, 2) + chkbit(y, 1);
    if (m == 2)
        return cnt0 & 1;
    else
        return cnt0 & 1 && cnt1 & 1;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            a[i][j] = c == '1';
        }
    if (n >= 4 && m >= 4)
        print(-1);
    else {
        if (n < m) {
            vector<vector<int>> b(m, vector<int>(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) b[j][i] = a[i][j];
            a = b;
            swap(n, m);
        }
        if (m == 1) {
            print(0);
        } else {
            int p2 = 1 << m;
            vi x(n);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (a[i][j]) x[i] += 1 << j;

            vvi dp(2, vi(p2, -1));

            int p = 0, q = 1;
            for (int i = 0; i < p2; ++i) dp[q][i] = diff(i, x[0]);

            for (int i = 1; i < n; ++i) {
                swap(p, q); 
                for (int k = 0; k < p2; ++k) dp[q][k] = -1;
                for (int k = 0; k < p2; ++k)
                    for (int l = 0; l < p2; ++l)
                        if (test(k, l, m) && dp[p][k] != -1) {
                            int val = dp[p][k] + diff(l, x[i]);
                            dp[q][l] =
                                dp[q][l] == -1 ? val : min(dp[q][l], val);
                        }
            }

            int ans = -1;
            for (int i = 0; i < p2; ++i)
                if (dp[q][i] != -1)
                    ans = ans == -1 ? dp[q][i] : min(dp[q][i], ans);
            print(ans);
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

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