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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<unordered_map<int, int>> ratio(n + 1);
    int d = 0, k = 0;
    for (int i = 0; i < n; ++i) {
        auto &c = s[i];
        if (c == 'D')
            d++;
        else
            k++;

        if (d > 0 && k > 0) {
            int g = gcd(d, k);
            int rd = d / g;
            int rk = k / g;
            ratio[rd][rk] += 1;
            cout << ratio[rd][rk] << " \n"[i == n - 1];
        } else if (d == 0) {
            cout << k << " \n"[i == n - 1];
        } else {
            cout << d << " \n"[i == n - 1];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

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