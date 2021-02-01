#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int& i : a) cin >> i;
    int cnt = 0;
    ll ans = 0;
    string s;
    cin >> s;
    multiset<int> tmp;
    for (int i = 0; i < n; ++i) {
        if (!i) {
            ++cnt;
            tmp.insert(a[i]);
        } else {
            if (s[i] == s[i - 1]) {
                ++cnt;
                tmp.insert(a[i]);
            } else {
                while (cnt > k) {
                    ans = ans - (*tmp.begin());
                    tmp.erase(tmp.begin());
                    cnt--;
                }
                tmp.clear();
                cnt = 1;
                tmp.insert(a[i]);
            }
        }
        ans = ans + a[i];
    }
    while (cnt > k) {
        ans = ans - (*tmp.begin());
        tmp.erase(tmp.begin());
        cnt--;
    }
    cout << ans << endl;
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
