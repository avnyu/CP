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

// An array of length n where the i-th element is the length of the longest
// substring starting from i that also a prefix of s.
void z_function(string &s, vi &z) {
    int n = s.size(), i, j = 0;
    z.assign(n, 0);
    for (i = 1; i < n; ++i) {
        if (j + z[j] > i) z[i] = min(j + z[j] - i, z[i - j]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > j + z[j]) j = i;
    }
}

vvi dp, z2d;

int cal(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 1;

    dp[l][r] = r - l + 1;
    for (int i = l + 1; i <= r; ++i) {
        int t = i - l;

        for (int j = 0; j <= z2d[l][i] && i + j <= r; j += t)
            dp[l][r] = min(dp[l][r], cal(l, i - 1) + cal(i + j, r));

        if (i + z2d[l][i] > r && (r - l + 1) % t == 0)
            dp[l][r] = min(dp[l][r], cal(l, i - 1));
    }

    return dp[l][r];
}
bool solve() {
    string s;
    cin >> s;
    if (s == "*") return false;

    int n = s.size();

    z2d.assign(n, vi(n));
    for (int i = 0; i < n; ++i) {
        vi z;
        string t = s.substr(i);
        z_function(t, z);
        for (int j = i; j < n; ++j) z2d[i][j] = z[j - i];
    }

    dp.assign(n, vi(n, -1));
    cout << cal(0, n - 1) << '\n';

    
    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < n; ++j) cout << dp[i][j] << " \n"[j == n - 1];

    return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // int t = 1;
    // cin >> t;
    // for (int i = 0; i++ < t;) solve();
    while (solve()) {}

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