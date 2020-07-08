#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int L = 0, R = n - 1;
    while (L <= R && s[L] == s[R]) L++, R--;
    if (L > R) {
        write(s);
        return;
    }

    string remain(s.begin() + L, s.begin() + R + 1);

    n = remain.size();
    int mx1 = -1, mn1 = -1, mx2 = -1, mn2 = -1;

    vector<int> d1(n);
    int rsl = 0, rsr = 0;

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

        while (0 <= i - k && i + k < n && remain[i - k] == remain[i + k]) k++;

        d1[i] = k--;

        if (i + k > r) {
            l = i - k;
            r = i + k;
        }

        if (i + 1 == d1[i] && d1[i] + d1[i] - 1 > rsr - rsl) {
            rsl = 0;
            rsr = i + d1[i];
        }
        if (i + d1[i] == n && d1[i] + d1[i] - 1 > rsr - rsl) {
            rsl = i + 1 - d1[i];
            rsr = n;
        }
    }

    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

        while (0 <= i - k - 1 && i + k < n &&
               remain[i - k - 1] == remain[i + k])
            k++;

        d2[i] = k--;

        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }

        if (i && i == d2[i] && d2[i] + d2[i] > rsr - rsl) {
            rsl = 0;
            rsr = i + d2[i];
        }
        if (i + d2[i] == n && d2[i] + d2[i] > rsr - rsl) {
            rsl = i - d2[i];
            rsr = n;
        }
    }

    for (int i = 0; i < L; ++i) cout << s[i];
    for (int i = rsl; i < rsr; ++i) cout << remain[i];
    for (int i = R + 1; i < s.size(); ++i) cout << s[i];
    cout << '\n';

    // write(rsl, rsr);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void write() {
    cout << "\n";
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}