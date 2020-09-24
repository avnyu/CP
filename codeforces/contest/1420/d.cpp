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

const int N = 3e5 + 7;
const int M = 998244353;
vll fact(N);

int fpow(int b, int n, int m) {
    ll rs = 1;
    while (n) {
        if (n & 1)rs = rs * b % m;
        n >>= 1;
        b = 1LL * b * b % m;
    }
    return rs;
}
int gcd_ex(int x, int m) {
    return fpow(x, m - 2, m);
}
int C(int x, int n) {
    return fact[n] * gcd_ex(fact[x], M) % M * gcd_ex(fact[n - x], M) % M;
}
void init() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % M ;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vii a;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.push_back(ii{l, 0});
        a.push_back(ii{r, 1});
    }
    sort(all(a));
    int cur = 0;
    ll ans = 0;
    for (auto&i : a) {
        if (!i.se) {
            cur++;
            if (cur >= k) {
                ans = (ans + C(k - 1, cur - 1)) % M;
            }
        } else {
            cur--;
        }
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    init();

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