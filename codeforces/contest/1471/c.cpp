#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

void solve() {
    int n, m;
    cin >> n >> m;
    vi k(n), c(m);
    for (int i = 0; i < n; ++i) cin >> k[i];
    for (int i = 0; i < m; ++i) cin >> c[i];
    sort(k.begin(), k.end());

    ll sum = 0;
    for (int i = n, j = 1; i--;) {
        if (j < k[i]) {
            sum += c[j - 1];
            j++;
        } else {
            sum += c[k[i] - 1];
        }
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