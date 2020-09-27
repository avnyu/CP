#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll M;
vector<vector<pair<int, int>>> prime;

void init() {
    int N = 1e6 + 7;

    prime.resize(N);
    for (int i = 2; i < N; ++i) {
        if (prime[i].empty()) {
            int j = i;
            while (j < N) {
                prime[j].push_back({i, 0});
                j += i;
            }
        }
    }

    for (int i = 2; i < N; ++i) {
        int y = i;
        for (auto& j : prime[i]) {
            while (y % j.first == 0) {
                j.second++;
                y /= j.first;
            }
        }
    }
}

void mul(ll a[2][2], ll b[2][2]) {
    ll c[2][2] = {{0, 0}, {0, 0}};
    for (ll i = 0; i < 2; ++i)
        for (ll j = 0; j < 2; ++j)
            for (ll k = 0; k < 2; ++k)
                c[i][j] = (1LL * a[i][k] * b[k][j] + c[i][j]) % M;
    for (ll i = 0; i < 2; ++i)
        for (ll j = 0; j < 2; ++j) a[i][j] = c[i][j];
}
void pow(ll a[2][2], ll n) {
    ll res[2][2] = {{1, 0}, {0, 1}};
    while (n) {
        if (n & 1) mul(res, a);
        n >>= 1;
        mul(a, a);
    }
    for (ll i = 0; i < 2; ++i)
        for (ll j = 0; j < 2; ++j) a[i][j] = res[i][j];
}

ll pow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * x) % M;
        n >>= 1;
        x = (x * x) % M;
    }
    return res;
}

ll C(ll x) {
    int N = 1e6 + 7;
    vector<ll> cnt(N, 0);

    for (int i = 2; i + i <= x; ++i) {
        int y = i;
        for (auto& j : prime[i]) cnt[j.first] -= j.second;
    }
    for (int i = (x >> 1) + 1; i <= x; ++i) {
        int y = i;
        for (auto& j : prime[i]) cnt[j.first] += j.second;
    }

    ll res = 1;
    for (ll i = 1; i <= x; ++i) res = (res * pow(i, cnt[i])) % M;

    return res;
}

ll cal(ll x) {
    ll res = 0;
    auto chk_bit = [](ll msk, ll p) { return (msk & (1LL << p)) > 0; };

    for (ll mask = 0; mask < (1 << x); ++mask) {
        ll y = mask, cnt = 0;
        for (ll i = 0; i < x; ++i) cnt += chk_bit(mask, i);
        if (cnt + cnt == x) {
            res++;
            continue;
        }

        bool chk = true;
        for (ll i = 1; i < x; ++i) {
            if (chk_bit(mask, i - 1) && chk_bit(mask, i)) {
                chk = false;
                break;
            }
        }
        res += chk;
    }
    return res % M;
}

void solve() {
    ll n;
    cin >> n >> M;

    ll a[2][2] = {{1, 1}, {0, 0}};
    ll b[2][2] = {{1, 1}, {1, 0}};

    pow(b, n - 1LL);
    mul(a, b);

    ll res = (a[0][0] + a[0][1]) % M;

    if (!(n & 1LL)) {
        ll tmp = C(n);

        res = (res + tmp) % M;
        res = (res + M - ((n >> 1LL) % M));
        res = (res + M - 1) % M;
    }

    cout << res << '\n';
    // cout << cal(n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("in", "r", stdin);

    init();

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}