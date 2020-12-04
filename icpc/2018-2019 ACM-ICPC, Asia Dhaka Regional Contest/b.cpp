#include <bits/stdc++.h>

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
#define debug(x) cerr << #x << ' ' << x << '\n'
#define prt(vec)                                                               \
    for (auto &vt : vec) cout << setw(2) << vt << " \n"[&vt == &vec.back()];
#define iii tuple<int, int, int>
#define lll tuple<ll, ll, ll>
#define pb push_back
#define vl vector<ll>

using namespace std;

void print();
template <typename T, typename... Args> void print(T x, Args... args);

vl p10(19, 1);

void init() {
    for (int i = 1; i < 19; ++i) p10[i] = p10[i - 1] * 10;
}
lll split(ll n, int i, int j) {
    ll l, m, r;
    l = n / p10[i];
    m = n % p10[i] / p10[j];
    r = n % p10[j];
    return lll{l, m, r};
}
ll get(ll n) {
    ll res = 0;
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < i; ++j) {

            auto [l, m, r] = split(n, i, j);

            int ig = 9 - l % 10, is = l % 10;
            int jg = 9 - m % 10, js = m % 10;

            l /= 10;
            m /= 10;
        }
    return res;
}
void solve(int T) {
    ll u, v;
    cin >> u >> v;

    get(v);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    init();

    int t = 1;
    cin >> t;
    for (int i = 0; i++ < t;) solve(i);

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args> void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << endl;
    }
}
