#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b;
    for (auto& i : a) cin >> i;
    b = a;
    sort(b.begin(), b.end(), greater<int>());
    int cnt = 0;
    multiset<int> s;
    for (int i = 0; i < m * k; ++i) s.insert(b[i]);
    ll ans = 0;
    b.clear();
    for (int i = 0; i < n; ++i) {
        if (s.find(a[i]) != s.end()) {
            cnt++;
            ans = ans + a[i];
            s.erase(s.find(a[i]));
        }
        if (cnt == m) {
            cnt = 0;
            b.push_back(i + 1);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < k - 1; ++i) cout << b[i] << ' ';
}
int main() {
    FIO;
    // srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--) { solve(); }
    return 0;
}
