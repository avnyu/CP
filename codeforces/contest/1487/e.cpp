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

const int N = 2e5 + 7;
vi a(N), b(N), c(N), d(N);
vvi x(N), y(N), z(N);

void solve(int T) {
    int n1, n2, n3, n4;
    int m1, m2, m3;

    cin >> n1 >> n2 >> n3 >> n4;
    for (int i = 0; i < n1; ++i) cin >> a[i];
    for (int i = 0; i < n2; ++i) cin >> b[i];
    for (int i = 0; i < n3; ++i) cin >> c[i];
    for (int i = 0; i < n4; ++i) cin >> d[i];


    cin >> m1;
    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        x[v].push_back(u);
    }

    cin >> m2;
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        y[v].push_back(u);
    }
    cin >> m3;
    for (int i = 0; i < m3; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        z[v].push_back(u);
    }

    multiset<int> h1, h2, h3, h4;


    for (int i = 0; i < n1; ++i) h1.insert(a[i]);

    for (int i = 0; i < n2; ++i) {
        for (auto &v : x[i]) h1.erase(h1.find(a[v]));

        if (h1.empty())
            b[i] = -1;
        else {
            b[i] += *h1.begin();
            h2.insert(b[i]);
        }

        for (auto &v : x[i]) h1.insert(a[v]);
    }

    for (int i = 0; i < n3; ++i) {
        for (auto &v : y[i])
            if (b[v] != -1) h2.erase(h2.find(b[v]));

        if (h2.empty())
            c[i] = -1;
        else {
            c[i] += *h2.begin();
            h3.insert(c[i]);
        }

        for (auto &v : y[i])
            if (b[v] != -1) h2.insert(b[v]);
    }

    for (int i = 0; i < n4; ++i) {
        for (auto &v : z[i])
            if (c[v] != -1) h3.erase(h3.find(c[v]));

        if (h3.empty())
            d[i] = -1;
        else {
            d[i] += *h3.begin();
            h4.insert(d[i]);
        }

        for (auto &v : z[i])
            if (c[v] != -1) h3.insert(c[v]);
    }

    if (h4.empty())
        print(-1);
    else
        print(*h4.begin());
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T X, Args... args) {
    if (sizeof...(args)) {
        cout << X << ' ';
        print(args...);
    } else {
        cout << X << '\n';
    }
}