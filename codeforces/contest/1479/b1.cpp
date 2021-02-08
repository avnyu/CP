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
    vii a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (a.empty() || a.back().fi != x)
            a.push_back(ii{x, 1});
        else
            a.back().se++;
    }
    vi res(4, 0);

    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i].se > 1) {
            res[0] += a[i].fi != res[2];
            res[1] += a[i].fi != res[3];
            res[2] = res[3] = a[i].fi;
        } else {
            if (a[i].fi == res[2]) {
                res[1] += a[i].fi != res[3];
                res[3] = a[i].fi;
            } else if (a[i].fi == res[3]) {
                res[0] += a[i].fi != res[2];
                res[2] = a[i].fi;
            } else if (i + 1 < (int)a.size()) {
                if (res[2] == a[i + 1].fi) {
                    res[0] += a[i].fi != res[2];
                    res[2] = a[i].fi;
                } else if (res[3] == a[i + 1].fi) {
                    res[1] += a[i].fi != res[3];
                    res[3] = a[i].fi;
                } else {
                    res[0] += a[i].fi != res[2];
                    res[2] = a[i].fi;
                }
            } else {
                res[0] += a[i].fi != res[2];
                res[2] = a[i].fi;
            }
        }
    }
    print(res[0] + res[1]);
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