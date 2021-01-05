#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& i : a) cin >> i.first >> i.second;
    for (auto& i : a)
        if (i.first > i.second) swap(i.first, i.second);

    auto b = a;
    sort(b.begin(), b.end());

    for (int i = 1; i < n; ++i) b[i].second = min(b[i - 1].second, b[i].second);

    for (int i = 0, l, add; i < n; ++i) {
        if (a[0].first < a[i].first && a[0].second < a[i].second) {
            cout << 1 << " \n"[i == n - 1];
            continue;
        }
        l = 0;
        add = 1 << 20;
        while (add) {
            if (l + add < n && b[l + add].second >= a[i].second) l += add;
            add >>= 1;
        }
        l++;
        if (l == n || b[l].first >= a[i].first)
            cout << -1 << " \n"[i == n - 1];
        else
            cout << l + 1 << " \n"[i == n - 1];
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}