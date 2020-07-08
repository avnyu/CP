#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int M = 1e9 + 7;

void solve() {
    int h1, h2, a;
    double m1, m2;
    char c;
    cin >> h1 >> c >> m1 >> h2 >> c >> m2 >> a;

    int cnt = 0;
    vector<double> save(4);

    auto get_minute = [&](vector<double>& s, int h, int a) {
        h = h % 12;
        double from_angle = -double(h) * 360.0 / 12.0;
        double angle_per_minute = 360.0 / 60.0 - 360.0 / 12.0 / 60.0;
        s[0] = double(-from_angle + (a - 360)) / angle_per_minute;
        s[1] = double(-from_angle + (-a)) / angle_per_minute;
        s[2] = double(-from_angle + (a)) / angle_per_minute;
        s[3] = double(-from_angle + (360 - a)) / angle_per_minute;
        return 0;
    };

    auto ok_minute = [&](int h, double m, int h1, double m1, int h2,
                         double m2) {
        if (h == h1 && h == h2) return (m1 <= m) && (m <= m2);
        if (h == h1) return (m1 <= m) && (m < 60.0);
        if (h == h2) return (0.0 <= m) && (m <= m2);
        return (0.0 <= m) && (m < 60.0);
    };

    for (int i = 0; i < 24; ++i) {
        if (i >= h1 && i <= h2) {
            get_minute(save, i, a);
            for (auto& m : save) cnt += ok_minute(i, m, h1, m1, h2, m2);
        }
    }

    cout << cnt / (1 + (a != 90)) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}