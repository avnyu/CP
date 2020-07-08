#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> st(8e5 + 7);
vector<pair<int, int>> h(2e5 + 7);

int up(int p, int val, int i = 1, int l = 0, int r = n - 1) {
    if (p < l || p > r) return st[i];
    if (p == l && p == r) return st[i] = val;
    int md = (l + r) >> 1;
    return st[i] =
               max(up(p, val, i + i, l, md), up(p, val, i + i + 1, md + 1, r));
}
int get(int b, int e, int i = 1, int l = 0, int r = n - 1) {
    if (r < b || l > e) return 0;
    if (b <= l && r <= e) return st[i];
    int md = (l + r) >> 1;
    return max(get(b, e, i + i, l, md), get(b, e, i + i + 1, md + 1, r));
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        up(i, x);
    }
    cin >> m;

    for (int i = 0; i < m; ++i) cin >> h[i].first >> h[i].second;
    sort(h.begin(), h.begin() + m);
    for (int i = m - 1; i; --i)
        h[i - 1].second = max(h[i - 1].second, h[i].second);

    int p = 0, res = 0;

    while (p != n) {
        int l = p, r = n - 1, nxt = -1;
        //cout << "test " << p << ' ' << res << ' ' << l << ' ' << r << '\n';

        while (l <= r) {
            int md = (l + r) >> 1;
            int power = get(p, md);
            int pos =
                lower_bound(h.begin(), h.begin() + m, make_pair(power, 0)) -
                h.begin();

            if (pos != m && h[pos].second >= md - p + 1)
                nxt = l = md + 1;
            else
                r = md - 1;
        }

        if (nxt == -1) {
            cout << "-1\n";
            return;
        }
        p = nxt;
        res++;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, M = 1e9;
    cin >> t;
    while (t--) solve();

    return 0;
}