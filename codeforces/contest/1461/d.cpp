#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<ll>s;

void dfs(vector<int> &a, vector<ll> &pre, int l, int r) {
    if (l > r) return;
    if (l == r) {
        s.insert(a[l]);
        return;
    }
    
    s.insert(pre[r] - pre[l - 1]);
    
    int m = upper_bound(a.begin() + l, a.begin() + r + 1, (a[l] + a[r]) / 2) - a.begin();
    
    // cout << l << " " << m << " " << r << endl;
    
    if (r != m - 1) dfs(a, pre, l, m - 1);
    if (m != l) dfs(a, pre, m, r);
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    sort(a.begin() + 1, a.begin() + 1 + n);
    
    vector<ll> pre(n + 2);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    
    s.clear();
    dfs(a, pre, 1, n);
    
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << (s.find(x) == s.end() ? "No" : "Yes") << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}
