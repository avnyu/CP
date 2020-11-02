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

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + 2, n + 2), pos(n + 1);
    for (int i = 0; i++ < n;) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        pos[x] = i + 1;
    }
    for (int i = 0; i++ < n;) a[i] = pos[a[i]];
    // for (int i = 0; i++ < n;) cout << a[i] << " \n"[i == n];
    int res = 1, M = 998244353;
    for (int i = 0; i++ < n;) {
        if (a[i] && a[i - 1] > a[i] && a[i + 1] > a[i]) {
            print("0");
            return;
        }
        if (a[i] && a[i - 1] < a[i] && a[i + 1] < a[i]) res = res * 2 % M;
    }
    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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