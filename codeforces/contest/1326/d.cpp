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

string res;

ii pan(string &s) {
    const int n = s.size();
    vi d1(n, 0), d2(n, 0);

    int k = 0, r = 0, l = 0;
    for (int i = 0; i < n; ++i) {
        if (i < k + d1[k]) d1[i] = min(d1[k + k - i], k + d1[k] - i);

        while (i + d1[i] < n && i - d1[i] >= 0 && s[i + d1[i]] == s[i - d1[i]])
            d1[i]++;

        if (i + d1[i] > k + d1[k]) k = i;

        if (i + 1 == d1[i] && d1[i] + d1[i] - 1 > r - l) {
            l = 0;
            r = i + d1[i];
        }
        if (i + d1[i] == n && d1[i] + d1[i] - 1 > r - l) {
            l = i + 1 - d1[i];
            r = n;
        }
    }

    k = 0;
    for (int i = 0; i < n; ++i) {
        if (i < k + d2[k]) d2[i] = min(d2[k + k - i], k + d2[k] - i);

        while (i + d2[i] < n && i - d2[i] > 0 &&
               s[i + d2[i]] == s[i - 1 - d2[i]])
            d2[i]++;

        if (i + d2[i] > k + d2[k]) k = i;

        if (i - d2[i] == 0 && d2[i] + d2[i] > r - l) {
            l = 0;
            r = i + d2[i];
        }
        if (i + d2[i] == n && d2[i] + d2[i] > r - l) {
            l = i - d2[i];
            r = n;
        }
    }
    return {l, r};
}

bool isPan(string &s) {
    int l = 0, r = s.size() - 1;
    while (l <= r && s[l] == s[r]) l++, r--;
    return l > r;
}

void solve() {
    string s;
    cin >> s;
    const int n = s.size();
    int l = 0, r = n - 1;
    while (l <= r && s[l] == s[r]) l++, r--;

    if (l > r) {
        res += s;
        return;
    }

    // write(s, l, r);

    string s1 = s.substr(l, n - l - l);

    ii t1 = pan(s1);

    res +=
        s.substr(0, l) + s1.substr(t1.fi, t1.se - t1.fi) + s.substr(n - l, l);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    write(res);

    return 0;
}

template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}