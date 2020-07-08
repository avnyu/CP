#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

vector<char> a(100, '0');
vector<bool> chk(128, true);

void solve() {
    fill(all(a), '0');
    fill(all(chk), true);
    string s;
    cin >> s;

    int p = 50, l = 99, r = 0;
    for (auto& i : s) {
        if (a[p + 1] == i) {
            p++;
        } else if (a[p - 1] == i) {
            p--;
        } else if (a[p + 1] == '0') {
            if (!chk[i]) {
                cout << "NO\n";
                return;
            }
            chk[i] = false;
            a[++p] = i;
            l = min(l, p);
            r = max(r, p);
        } else if (a[p - 1] == '0') {
            if (!chk[i]) {
                cout << "NO\n";
                return;
            }
            chk[i] = false;
            a[--p] = i;
            l = min(l, p);
            r = max(r, p);
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 97; i < 123; ++i)
        if (chk[i]) a[++r] = i;
    for (int i = l; i <= r; ++i) cout << a[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}