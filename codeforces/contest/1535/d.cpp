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
    for (auto& iv : v) cout << iv << " \n"[&iv == &v.back()]
#define gmax(a, b) \
    if (b > a) a = b
#define gmin(a, b) \
    if (b < a) a = b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    int n = 1 << k;
    vll a(n << 1, 1);
    reverse(s.begin(), s.end());
    s = '0' + s;

    auto upd = [&](int p) {
        if (s[p] == '1')
            a[p] = a[p << 1];
        else if (s[p] == '0')
            a[p] = a[p << 1 | 1];
        else
            a[p] = a[p << 1] + a[p << 1 | 1];
    };

    for (int i = n - 1; i; --i) {
        int j = i;
        while (j) {
            upd(j);
            j >>= 1;
        }
    }

    // prt(a);
    // print(s);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int p;
        char c;

        cin >> p >> c;
        p = n - p;

        s[p] = c;
        while (p) {
            upd(p);
            p >>= 1;
        }

        // prt(a);
        // print(s);
        print(a[1]);
    }
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