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

vvi ans(151, vi(10, -1));

int cal(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
void init() {
    const int N = 1e6;
    vi s(N);
    for (int i = 0; i < N; ++i) s[i] = cal(i);
    vvi res(N, vi(10));
    for (int i = 0; i < N; ++i) res[i][0] = s[i];
    for (int j = 1; j < 10; ++j)
        for (int i = 0; i < N; ++i) {
            if (i + j < N)
                res[i][j] = res[i][j - 1] + s[i + j];
            else
                res[i][j] = -1;
        }
    for (int j = 0; j < 10; ++j)
        for (int i = 0; i < N; ++i)
            if (res[i][j] > 0 && res[i][j] < 151 && ans[res[i][j]][j] == -1)
                ans[res[i][j]][j] = i;
}
ll cal0(int n) {
    stack<int> s;
    while (n) {
        s.push(min(n, 9));
        n -= min(n, 9);
    }
    ll res = 0;
    while (s.size()) {
        res = res * 10 + s.top();
        s.pop();
    }
    return res;
}
ll cal08(int n) {
    int red = 1;
    stack<int> s;
    while (n) {
        s.push(min(n, 9 - red));
        n -= min(n, 9 - red);
        if (red) red--;
    }
    ll res = 0;
    while (s.size()) {
        res = res * 10 + s.top();
        s.pop();
    }
    return res;
}
ll cal1(int n) {
    if (n & 1) {
        ll res = 1e18;
        for (int i = 0; i < 9; ++i)
            if (n >= i + i + 1) {
                res = min(res, cal0((n - i - i - 1) / 2) * 10 + i);
            }
        return res == 1e18 ? -1 : res;
    }
    if (n < 10) return -1;

    ll res = 1e9;
    res = cal08((n - 10) / 2) * 10 + 9;
    return res == 1e9 ? -1 : res;
}
void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << cal0(n) << '\n';
    } else if (k == 1) {
        cout << cal1(n) << '\n';
    } else {
        cout << ans[n][k] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    init();

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    cout << x << ' ';
    print(args...);
}
