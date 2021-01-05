#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, k;
    cin >> n >> k;
    queue<ii> q;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        q.push({x, x});
    }
    ll sum = 0;
    while (!q.empty()) {
        auto &x = q.front();
        if (x.first % k == 0) {
            sum += x.second;
            q.push({x.first / k, x.second});
            q.pop();
        } else
            break;
    }
    while (!q.empty()) {
        auto &x = q.front();
        sum += x.second;
        q.pop();
    }
    cout << sum << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}