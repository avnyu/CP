#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))
#define pll pair<ll, ll>
#define vl vector<ll>

using namespace std;

bool ccw(double &ax, double &ay, double &bx, double &by, double &cx,
         double &cy) {
    return (bx - ax) * (cy - ay) > (cx - ax) * (by - ay);
}

vi convexhull(vector<double> &x, vector<double> &y) {
    int n = x.size(), cur;
    vi res = {0, 1};
    res.reserve(n);
    for (int i = 2; i < n; ++i)
        while (1) {
            cur = res.size();
            if (cur == 1) {
                res.eb(i);
                break;
            } else if (ccw(x[res[cur - 2]], y[res[cur - 2]], x[res[cur - 1]],
                           y[res[cur - 1]], x[i], y[i])) {
                res.eb(i);
                break;
            } else
                res.pop_back();
        }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<double> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        y[i] = y[i - 1] + double(a);
    }
    iota(all(x), 0);

    vi res = convexhull(x, y);
    // for (auto& i : res) cout << i << " \n"[i == res.back()];

    cout << fixed << setprecision(9);
    for (int i = 1; i < res.size(); ++i) {
        int &l = res[i - 1], &r = res[i];
        double x = (double(y[r]) - y[l]) / (r - l);
        while (l++ < r) cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}