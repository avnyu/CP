#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(u, v) \
    for (auto x = u; x != v;) cout << (*x) << " \n"[++x == v];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void z_function(string &s, vi &z);
void prefix_function(string &s, vi &z);

void solve(int T, int E) {
    string s;
    cin >> s;

    int n = s.size();
    vi z;
    z_function(s, z);

    int t = n;
    for (int i = 1; i < n; i++)
        if (n % i == 0 && i + z[i] == n) {
            t = i;
            break;
        }

    cout << t << (T == E ? "\n" : "\n\n");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 0; i++ < t;) solve(i, t);

    return 0;
}

// An array of length n where the i-th element is the length of the longest
// substring starting from i that also a prefix of s.
void z_function(string &s, vi &z) {
    int n = s.size(), i, j = 0;
    z.assign(n, 0);
    for (i = 1; i < n; ++i) {
        if (j + z[j] > i) z[i] = min(j + z[j] - i, z[i - j]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > j + z[j]) j = i;
    }
}
// WIP
// An array of length n where the i-th element is the length of the longest
// proper prefix which is also a suffix of substring s[0..i]
void prefix_function(string &s, vi &z) {
    int n = s.size(), i;
    z.assign(n, 0);
    int j = 0;
}