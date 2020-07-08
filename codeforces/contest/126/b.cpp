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

    const int n = s.size();

    if (n < 3) {
        write("Just a legend");
        return;
    }

    vi z(n);
    z[0] = n;

    vi suf(n);

    int k = 1, mid = 0;
    for (int i = 1; i < n; ++i) {
        if (i < k + z[k]) z[i] = min(z[i - k], k + z[k] - i);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > k + z[k]) k = i;

        if (i + z[i] == n) suf[z[i]] = 1;
        mid = max(mid, z[i] - (i + z[i] == n));
    }

    for (int i = mid; i; i--)
        if (suf[i]) {
            write(s.substr(0, i));
            return;
        }

    write("Just a legend");
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

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