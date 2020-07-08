#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
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
template <typename T>
void print_all(vector<T>& a);

const int N = 1e5 + 7;
string s, res(N, '0');
int n;

void dp(int p, int low, int num4, int num7) {
    if (low) {
        cout << res.substr(0, p) + string(n / 2 - num4, '4') +
                    string(n / 2 - num7, '7') + '\n';
        exit(0);
    }
    if (p == n) {
        cout << res.substr(0, n) + '\n';
        exit(0);
    }
    if (s[p] <= '4' && num4 + num4 < n) {
        res[p] = '4';
        dp(p + 1, low || (s[p] < '4'), num4 + 1, num7);
    }
    if (s[p] <= '7' && num7 + num7 < n) {
        res[p] = '7';
        dp(p + 1, low || (s[p] < '7'), num4, num7 + 1);
        res.pop_back();
    }
}

void solve() {
    cin >> s;
    n = s.size();
    if (n & 1)
        cout << string(n / 2 + 1, '4') + string(n / 2 + 1, '7') + '\n';
    else if (s > string(n / 2, '7') + string(n / 2, '4'))
        cout << string(n / 2 + 1, '4') + string(n / 2 + 1, '7') + '\n';
    else
        dp(0, 0, 0, 0);
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (auto i = a.begin(); i != a.end();) cout << *i << " \n"[++i == a.end()];
}