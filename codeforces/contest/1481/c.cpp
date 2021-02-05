#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(v) \
    for (auto &i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    int n, m;
    cin >> n >> m;
    vi a(n), b(n), c(m);
    vvi col(n + 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < m; ++i) cin >> c[i];

    int last = -1;
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i] && b[i] == c[m - 1]) last = i;
    if (last == -1)
        for (int i = 0; i < n; ++i)
            if (b[i] == c[m - 1]) last = i;

    if (last == -1) {
        print("NO");
        return;
    }

    for (int i = 0; i < n; ++i)
        if (b[i] != a[i] && i != last) col[b[i]].push_back(i);

    vi had(n + 1, -1), res(m);
    res[m - 1] = last;
    for (int i = 0; i < n; ++i) had[b[i]] = i;

    for (int i = 0; i < m - 1; ++i)
        if (col[c[i]].size() > 0) {
            col[c[i]];
            res[i] = col[c[i]].back();
            col[c[i]].pop_back();
        } else {
            res[i] = last;
        }

    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += col[i].size();

    if (sum == 0) {
        print("YES");
        for (int i = 0; i < m; ++i) cout << res[i] + 1 << " \n"[i == m - 1];
    } else
        print("NO");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 0; i++ < t;) solve(i);

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