#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n == 3) {
        cout << "Yes\n1\n1 2 3\n";
    } else if (n & 1) {
        vvi res;
        res.push_back(vi{1, 2, 3});
        for (int i = 2; i + 2 < n; i += 2)
            res.push_back(vi{i + 1, i + 2, i + 3});
        for (int i = n - 3; i - 2 >= 0; i -= 2)
            res.push_back(vi{i - 1, i, i + 1});

        cout << "Yes\n" << res.size() << '\n';
        for (auto& i : res) cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    } else {
        int t = 0;
        for (auto& i : a) t ^= i;
        if (t) {
            cout << "No\n";
            return;
        }
        vvi res;
        res.push_back(vi{1, 2, 3});
        for (int i = 2; i + 2 < n - 1; i += 2)
            res.push_back(vi{i + 1, i + 2, i + 3});
        for (int i = n - 4; i - 2 >= 0; i -= 2)
            res.push_back(vi{i - 1, i, i + 1});

        cout << "Yes\n" << res.size() << '\n';
        for (auto& i : res) cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    }
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
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << endl;
    }
}