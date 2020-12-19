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
    vi a(n + 3), b(n + 3);
    for (int i = 0; i++ < n + 1;) cin >> a[i];
    for (int i = 0; i++ < n;) cin >> b[i];

    map<int, int> pos;
    for (int i = 0; i++ < n + 1;) pos[a[i]] = i;
    sort(a.begin() + 1, a.begin() + n + 2);

    vi lef(n + 3), rig(n + 3);
    for (int i = 0; i++ < n;) {
        lef[i] = max(a[i] - b[i], 0);
        lef[i] = max(lef[i], lef[i - 1]);
    }
    for (int i = n; i; i--) {
        rig[i + 1] = max(a[i + 1] - b[i], 0);
        rig[i + 1] = max(rig[i + 1], rig[i + 2]);
    }

    vi res(n + 3);
    for (int i = 0; i++ < n + 1;) res[pos[a[i]]] = max(lef[i - 1], rig[i + 1]);
    for (int i = 0; i++ < n + 1;) cout << res[i] << " \n"[i == n + 1];

//     for (int i = 0; i++ < n + 1;) cout << a[i] << " \n"[i == n + 1];
//     for (int i = 0; i++ < n + 1;) cout << b[i] << " \n"[i == n + 1];
//     for (int i = 0; i++ < n + 1;) cout << lef[i] << " \n"[i == n + 1];
//     for (int i = 0; i++ < n + 1;) cout << rig[i] << " \n"[i == n + 1];
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
        cout << x << '\n';
    }
}