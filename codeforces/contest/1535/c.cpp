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
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]
#define gmax(a, b) \
    if (b > a) a = b
#define gmin(a, b) \
    if (b < a) a = b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    string s;
    cin >> s;
    int n = s.size(), u = 0;
    ll res = 0;
    vvi l(2, vi(2, 0));
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            l[u ^ 1][1] = l[u][0] + 1;
            l[u ^ 1][0] = 0;
        } else if (s[i] == '0') {
            l[u ^ 1][1] = 0;
            l[u ^ 1][0] = l[u][1] + 1;
        } else {
            l[u ^ 1][1] = l[u][0] + 1;
            l[u ^ 1][0] = l[u][1] + 1;
        }
        u ^= 1;
        // print(l[u][0], l[u][1]);
        res += max(l[u][0], l[u][1]);
    }
    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 0; i++ < t;) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}