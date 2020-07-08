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
    int n;
    string s;
    cin >> n >> s;

    vi mn(n), mx(n);
    int start = n;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == '<') mx[i + 1] = start--;
    }
    start = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<' && !mx[i]) {
            int j = i;
            while (j >= 0 && mx[j] == 0) mx[j--] = start++;
        }
    }
    if (!mx[n - 1]) {
        int j = n - 1;
        while (j >= 0 && mx[j] == 0) mx[j--] = start++;
    }

    start = n;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<' && !mn[i + 1]) {
            int j = i;
            while (j < n - 1 && s[j] == '<') j++;
            while (j > i) mn[j--] = start--;
        }
    }
    start = 1;
    if (!mn[n - 1]) {
        int j = n - 1;
        while (j >= 0 && mn[j] == 0) mn[j--] = start++;
    }
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == '<' && !mn[i]) {
            int j = i;
            while (j >= 0 && mn[j] == 0) mn[j--] = start++;
        }
    }

    for (int i = 0; i < n; ++i) cout << mn[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i) cout << mx[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}