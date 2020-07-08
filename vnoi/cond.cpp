#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

bool solve() {
    int n;
    cin >> n;
    if (n == -1) return false;

    n--;
    ll res = 0;
    vi fac(11, 1);
    rep(i, 2, 11) fac[i] = fac[i - 1] * i;
    rep(msk, 0, (1 << n)) {
        int lst = 1, cur = 1;
        rep(i, 0, n) {
            if ((1 << i) & msk) {
                cur++;
            } else {
                lst *= fac[cur];
                cur = 1;
            }
        }
        lst *= fac[cur];
        res += fac[n + 1] / lst;
        // cout << "test " << fac[n + 1] << ' ' << lst << '\n';
    }
    cout << res << '\n';
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (1)
        if (!solve()) break;
    return 0;
}