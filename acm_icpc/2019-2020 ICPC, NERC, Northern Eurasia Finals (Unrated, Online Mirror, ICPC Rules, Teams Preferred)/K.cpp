#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<ll> fac(21);

void init() {
    fac[0] = 1;
    for (int i = 1; i < 21; ++i) fac[i] = fac[i - 1] * i;
}

ll cal(vector<int> &cnt, ll sum, ll p) {
    if (!cnt[p]) return 0LL;
    ll res = 1;
    cnt[p]--;
    sum--;

    for (int i = 20; i >= 0; --i)
        for (int j = 0; j < cnt[i]; ++j) {
            res *= sum - max(i, 1) + 1;
            sum--;
        }

    for (int i = 0; i < 21; ++i) res /= fac[cnt[i]];
    // for (int i = 0; i < 21; ++i) cout << cnt[i] << " \n"[i == 20];
    // cout << p << ' ' << res << '\n';

    cnt[p]++;
    return res;
}

void solve() {
    ll n;
    cin >> n;

    vector<int> cnt(21, 0);
    int sum = 0;
    for (int i = 2; n; ++i) {
        cnt[n % i]++;
        n /= i;
        sum++;
    }

    ll res = 0;
    for (int i = 1; i < 21; ++i) res += cal(cnt, sum, i);

    cout << res - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    init();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}