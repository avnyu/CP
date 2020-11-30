#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    int n, k;
    cin >> n >> k;
    vl a(n);
    for (auto& i : a) cin >> i;
    ll l, r;
    cin >> l >> r;

    sort(a.begin(), a.end());
    ll bl = 0, br = 0, add;

    for (add = n; add--;) {
        if (l - a[add] >= 0) {
            l -= a[add];
            bl += 1LL << add;
        }
    }
    for (add = n; add--;) {
        if (r - a[add] >= 0) {
            r -= a[add];
            br += 1LL << add;
        }
    }

    vector<vvi> dp(n + 1, vvi(k + 1, vi(3)));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            for (int k = 0; k < 3; ++k) {
                
            }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
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