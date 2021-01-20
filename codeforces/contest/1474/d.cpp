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
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vi d = a;
    for (int i = 1; i < n; ++i) d[i] -= d[i - 1];

    int t = d[n - 1];
    vi p;
    for (int i = 1; i < n; ++i) if (t == ((n - i) & 1 ? 2 : -2) * (a[i] - a[i - 1])) p.push_back(i);

    int neg = 0;
    for (int i = 1; i < n; ++i) neg += d[i] < 0;

    auto change = [](int iold, int inew) {
        if (iold < 0 && inew >= 0) return -1;
        if (iold >= 0 && inew < 0) return 1;
        return 0;
    };

    bool ok = neg == 0 && t == 0;
    for (int j = (int)p.size() - 1, i = n - 1; j >= 0; --j) {
        // cerr << j << " " << i << " " << p[j] << endl;
        while (i >= p[j]) {
            int nd = d[i] - ((n - i) & 1 ? t : -t);
            neg += change(d[i], nd);
            i--;
        }
        int x = neg + change(d[i], d[i] + a[i + 1] - a[i]);
        // cerr << j << " " << i << " " << neg << " " << x << endl;
        if (x == 0) ok = true;
    }

    cout << (ok ? "YES\n" : "NO\n");
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