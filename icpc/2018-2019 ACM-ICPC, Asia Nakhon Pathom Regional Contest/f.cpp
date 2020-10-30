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
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const ll M = 1e9 + 7;
const int logN = 22;
vll ps(8, 0);
vll sum(logN, 1);

void solve(int T) {
    for (int i = 1; i < 8; ++i) ps[i] = ps[i - 1] + i;
    for (int i = 1; i < logN; ++i) sum[i] = sum[i - 1] * ps[7] % M;

    ll n;
    cin >> n;
    n++;

    ll bound = 1, pos = 0;
    while (bound <= n) {
        bound *= 7;
        pos++;
    }

    ll t = 0;
    if (n & 1)
        t = n % M * ((n + 1) / 2 % M) % M;
    else
        t = (n + 1) % M * (n / 2 % M) % M;

    ll res = 0, mul = 1;
    while (bound > 1) {
        pos--;
        bound /= 7;
        res = (res + sum[pos] * ps[n / bound] % M * mul % M) % M;
        // print("loop", n, pos, sum[pos], n / bound, ps[n / bound], res);
        mul = mul * (n / bound + 1) % M;
        n -= n / bound * bound;
    }
    res = (t + M - res) % M;

    cout << "Case " << T << ": " << res << '\n';
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