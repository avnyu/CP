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

vector<string> accept = {"RL", "RLL", "RRL", "RRLL"};

int diff(string a, string b) {
    int res = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) res += a[i] != b[i];
    return res;
}
int test(string S, int p) {
    int n = S.size() / 2;
    if (p >= n) return int(1e6);
    vi dp(n + 1, 1e6);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
        for (auto& s : accept) {
            int m = s.size();
            if (i + m <= n) {
                int dif = diff(S.substr(p + i, m), s);
                dp[i + m] = min(dp[i + m], dp[i] + dif);
            }
        }
    return dp[n];
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s;
    int res = 1e6;
    res = min(res, test(s, 0));
    res = min(res, test(s, 1));
    res = min(res, test(s, 2));
    res = min(res, test(s, 3));
    print(res);
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
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