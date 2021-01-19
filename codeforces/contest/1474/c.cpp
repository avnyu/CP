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

bool test(multiset<int> a, int x) {
    int u = *a.begin();
    int v = x - u;

    a.erase(a.begin());
    if (a.find(v) == a.end()) return false;
    a.erase(a.find(v));

    x = u;

    while (a.size()) {
        u = *a.begin();
        a.erase(a.begin());

        v = x - u;
        if (a.find(v) == a.end()) return false;
        a.erase(a.find(v));

        x = u;
    }

    return true;
}
void out(multiset<int> a, int x) {
    int u = *a.begin();
    int v = x - u;

    cout << "YES\n";
    cout << -x << '\n';
    cout << -u << " " << -v << '\n';

    a.erase(a.begin());
    a.erase(a.find(v));

    x = u;

    while (a.size()) {
        u = *a.begin();
        a.erase(a.begin());

        v = x - u;
        a.erase(a.find(v));

        cout << -u << " " << -v << '\n';

        x = u;
    }
}
void solve(int T) {
    int n;
    cin >> n;
    multiset<int> a;
    for (int i = 0; i < n + n; ++i) {
        int x;
        cin >> x;
        a.insert(-x);
    }

    for (auto& i : a)
        if (test(a, (*a.begin()) + i)) {
            out(a, (*a.begin()) + i);
            return;
        }

    cout << "NO\n";
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