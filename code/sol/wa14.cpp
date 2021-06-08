#include <bits/stdc++.h>
#define inf 1e18

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, s, l;
multiset<ll, less<ll> > Minim, DP;
multiset<ll, greater<ll> > Maxim;
const int M = 2e6 + 5;
ll dp[M], V[M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> l;
    for (ll i = 1; i <= n; i++) cin >> V[i];
    for (ll i = 1; i <= l; i++) {
        Minim.insert(V[i]);
        Maxim.insert(V[i]);
    }
    ll minim = *(Minim.begin());
    ll maxim = *(Maxim.begin());
    if (maxim - minim > s) {
        cout << -1;
        return 0;
    }
    dp[l] = 1;
    ll st = 1;
    for (ll i = l + 1; i <= n; i++) {
        Minim.insert(V[i]);
        Maxim.insert(V[i]);
        DP.insert(dp[i - l]);
        ll minim = *(Minim.begin());
        ll maxim = *(Maxim.begin());
        while (maxim - minim > s && Minim.size() > l) {
            Minim.erase(Minim.find(V[st]));
            Maxim.erase(Maxim.find(V[st]));
            DP.erase(DP.find(dp[st]));
            st++;
            minim = *(Minim.begin());
            maxim = *(Maxim.begin());
        }
        if (maxim - minim > s) {
            dp[i] = inf;
            continue;
        }
        ll good = dp[st - 1];
        if (!DP.empty()) good = min(dp[st - 1], *(DP.begin()));
        if (good == inf)
            dp[i] = inf;
        else
            dp[i] = good + 1;
    }
    if (dp[n] == inf)
        cout << -1;
    else
        cout << dp[n];
    return 0;
}