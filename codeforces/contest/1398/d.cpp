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
    #define iii tuple<int, int, int>

    using namespace std;

    void print();
    template <typename T, typename... Args>
    void print(T x, Args... args);

    void solve() {
        int n, m, p;
        cin >> n >> m >> p;
        vll a(n), b(m), c(p);
        for (auto& i : a) cin >> i;
        for (auto& i : b) cin >> i;
        for (auto& i : c) cin >> i;

        sort(rall(a));
        sort(rall(b));
        sort(rall(c));

        vector<iii> tmp;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                for (int k = 0; k <= p; ++k) tmp.push_back(iii{i, j, k});
        sort(all(tmp), [&](iii& a, iii& b) {
            return get<0>(a) + get<1>(a) + get<2>(a) <
                get<0>(b) + get<1>(b) + get<2>(b);
        });

        vector<vvll> dp(n + 1, vvll(m + 1, vll(p + 1, 0)));
        for (auto& x : tmp) {
            int i, j, k;
            tie(i, j, k) = x;
            if (i < n && j < m)
                dp[i + 1][j + 1][k] =
                    max(dp[i + 1][j + 1][k], dp[i][j][k] + a[i] * b[j]);
            if (i < n && k < p)
                dp[i + 1][j][k + 1] =
                    max(dp[i + 1][j][k + 1], dp[i][j][k] + a[i] * c[k]);
            if (j < m && k < p)
                dp[i][j + 1][k + 1] =
                    max(dp[i][j + 1][k + 1], dp[i][j][k] + b[j] * c[k]);
        }
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                for (int k = 0; k <= p; ++k)
                    dp[n][m][p] = max(dp[n][m][p], dp[i][j][k]);

        print(dp[n][m][p]);
    }
    int main() {
        // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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