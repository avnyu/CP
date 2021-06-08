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
    vi b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    set<int> s;
    s.insert(b[0]);
    auto cur = s.begin();

    for (int i = 1; i < n; ++i) {
        s.insert(b[i]);

        if ((*cur) == b[i]) continue;

        if (cur != s.begin()) {
            auto low = cur;
            --low;
            if ((*low) == b[i]) {
                cur = low;
                continue;
            }
        }

        auto hig = cur;
        hig++;
        if (hig != s.end() && (*hig) == b[i]) {
            cur = hig;
            continue;
        }

        print("NO");
        return;
    }
    print("YES");
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