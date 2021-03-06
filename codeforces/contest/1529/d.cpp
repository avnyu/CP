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
    const int M = 998244353;

    int n;
    cin >> n;
    vi num_div(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i) num_div[j] = (num_div[j] + 1) % M;
    int sum = 1, res = 1;
    for (int i = 1; i < n; ++i) {
        res = (num_div[i + 1] + sum) % M;
        sum = (sum + res) % M;
    }
    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
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