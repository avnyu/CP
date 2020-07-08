#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    int n;
    cin >> n;
    int t = 0;
    vector<tuple<int, bool, int>> a;
    queue<int> x;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.push_back(make_tuple(l, 0, i));
        a.push_back(make_tuple(r, 1, i));
    }
    sort(a.begin(), a.end());
    for (auto& i : a) {
        int x, z;
        bool y;
        tie(x, y, z) = i;
        if (y == 0)
            t++;
        else {
            t--;
            ans[z] = 1;
            if (t == 0) break;
        }
    }
    t = 0;
    for (auto& i : ans) {
        if (i == 0) {
            t = 1;
            i = 2;
        }
    }
    if (t == 0) {
        cout << -1 << endl;
        return;
    }
    for (auto& i : ans) cout << i << ' ';
    cout << endl;
}
int main() {
    FIO;
    // srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
