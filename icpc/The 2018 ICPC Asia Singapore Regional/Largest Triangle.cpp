#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli ccw(pair<lli, lli> a, pair<lli, lli> b, pair<lli, lli> c) {
    lli val = 1LL * (b.first - a.first) * (c.second - a.second) -
              (c.first - a.first) * (b.second - a.second);
    return val;
}

lli len(pair<lli, lli> a, pair<lli, lli> b) {
    return (a.first - b.first) * (a.first - b.first) +
           (a.second - b.second) * (a.second - b.second);
}

lli s(pair<lli, lli> a, pair<lli, lli> b, pair<lli, lli> c) {
    return 1LL * a.first * (b.second - c.second) +
           1LL * b.first * (c.second - a.second) +
           1LL * c.first * (a.second - b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in", "r", stdin);

    lli n;
    cin >> n;
    vector<pair<lli, lli>> a(n);
    for (auto &i : a) cin >> i.first >> i.second;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();

    if (a.size() < 3) {
        cout << "0.0\n";
        return 0;
    }

    vector<lli> convex;
    convex.push_back(0);

    while (1) {
        lli i = convex.back();
        lli j = (i + 1) % n;
        for (lli k = 0; k < n; ++k) {
            if (k == j || k == i) continue;
            if (ccw(a[i], a[j], a[k]) < 0)
                j = k;
            else if (ccw(a[i], a[j], a[k]) == 0 &&
                     len(a[i], a[k]) > len(a[i], a[j]))
                j = k;
        }

        if (j == 0) break;
        convex.push_back(j);
    }

    // for (auto &i : convex) cout << i << ' ';
    // cout << '\n';

    lli res = 0;
    lli m = convex.size();

    for (lli i = 0; i < m - 2; ++i) {
        lli j = i + 1;
        lli k = j + 1;

        while (j < m - 1 && k < m) {
            // cout << i << ' ' << j << '\n';
            lli tmp = s(a[convex[i]], a[convex[j]], a[convex[k]]);

            while (k < m) {
                lli sk = s(a[convex[i]], a[convex[j]], a[convex[k]]);

                if (sk < tmp) break;

                tmp = sk;
                k++;
            }
            k--;
            res = max(res, tmp);
            j++;
        }
    }

    cout << res / 2 << (res & 1 ? ".5\n" : ".0\n");

    return 0;
}
