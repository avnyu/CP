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
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

const int M = 1e9;

pair<ll, ll> cal(ll c, ll m, ll rm) {
    ll l = m + c * rm;
    l = min(l, 1LL * M);

    ll r = m;
    for (int i = 0; i < rm; ++i) {
        c <<= 1;
        r += c;
        if (r > M) {
            r = M;
            break;
        }
    }
    return {l, r};
}
void solve() {
    int n;
    cin >> n;
    int k = 31 - __builtin_clz(n);

    write(k);

    ll c = 1, m = 1;
    for (ll i = 0; i < k; ++i) {
        // write("step", i + 1);

        ll cl = 0, cr = c;
        while (cl <= cr) {
            ll cm = cl + cr >> 1;

            ll l, r;
            tie(l, r) = cal(c + cm, m + c + cm, k - i - 1);

            if (r < n)
                cl = cm + 1;
            else if (n < l)
                cr = cm - 1;
            else {
                c += cm;
                m += c;
                cout << cm << " \n"[i == k - 1];
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}