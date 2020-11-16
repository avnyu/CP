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
    ll n, w;
    cin >> n >> w;
    vll a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        if (a[i].fi > w) {
            print(-1);
            return;
        }
        if (a[i].fi >= (w + 1) / 2) {
            print(1);
            print(a[i].se + 1);
            return;
        }
        if (i) {
            a[i].fi += a[i - 1].fi;
            if (a[i].fi >= (w + 1) / 2) {
                print(i + 1);
                for (int j = 0; j <= i; ++j)
                    cout << a[j].se + 1 << " \n"[j == i];
                return;
            }
        }
    }
    print(-1);
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