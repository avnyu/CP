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

void solve() {
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (auto& i : s)
        if (i == '1')
            cnt1++;
        else
            cnt0++;
    if (!cnt1) {
        cout << "0\n";
        return;
    }
    int i = 0;
    while (s[i] == '0') {
        cnt0--;
        i++;
    }
    i = s.size() - 1;
    while (s[i] == '0') {
        cnt0--;
        i--;
    }
    cout << cnt0 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;

    while (t--) solve();
    return 0;
}