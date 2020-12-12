#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int n, k;
vll h, a;
int cnt;

ll cal() {
    for (int i = 0; i < n; ++i) h[i] = a[i];
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        int l = i, r = i;
        
        for (int j = i; j >= 0; --j) l = h[j] > h[l] ? j : l;
        for (int j = i; j < n; ++j)  r = h[j] > h[r] ? j : r;
        
        ll v = min(h[l], h[r]);
        
        for (int j = l; j < r; ++j) if (h[j] < v) {
            res += v - h[j];
            h[j] = v;
        }
    }
    
    return res;
}
ll bf(ll add, int p = 0) {
    if (p == n) return cal();
    ll res = 0;
    for (int i = 0; i <= add; ++i) {
        a[p] += i;
        res = max(res, bf(add - i, p + 1));
        a[p] -= i;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> k;
    a.resize(n);
    h.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    cout << bf(k) << '\n';
 
    return 0;
}
