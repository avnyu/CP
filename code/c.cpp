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
    int n, s, l;
    cin >> n >> s >> l;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    const int M = 1e9 + 7;
    int j = 0;
    
    vi d(n + 1);
    for (int i = 1; i <= n; ++i) d[i] = M;
    
    deque<int> mx, mn, dp, ps;
    dp.push_back(0);
    ps.push_back(0);

    for (int i = 1; i <= n; ++i) {
        while (!mx.empty() && mx.back() < a[i]) mx.pop_back();
        while (!mn.empty() && mn.back() > a[i]) mn.pop_back();
        mx.push_back(a[i]);
        mn.push_back(a[i]);

        while (mx.front() - mn.front() > s) {
            if (ps.front() == j) {
                dp.pop_front();
                ps.pop_front();
            }
            ++j;
            if (mx.front() == a[j]) mx.pop_front();
            if (mn.front() == a[j]) mn.pop_front();
        }

        while (!dp.empty() && dp.back() == M) {
            dp.pop_back();
            ps.pop_back();
        }

        if (i - ps.front() >= l) d[i] = dp.front() + 1;
        dp.push_back(d[i]);
        ps.push_back(i);
    }
    
    print(d[n] == M ? -1 : d[n]);
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