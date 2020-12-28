#include <bits/stdc++.h>
using namespace std;

int cal(int x, int y) { return (x - 1) / y + 1; }
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> res;
    int a = n;
    for (int i = n - 1; i > 2; i--) {
        if (1LL * i * i <= a) {
            a = cal(a, i);
            res.push_back({n, i});
        }
        res.push_back({i, n});
    }
    while (a != 2) {
        a = cal(a, 2);
        res.push_back({n, 2});
    }
    res.push_back({n, 2});

    cout << res.size() << '\n';
    for (auto& i : res) cout << i[0] << " " << i[1] << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}