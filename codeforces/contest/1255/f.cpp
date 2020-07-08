#include <bits/stdc++.h>
#define lli long long
using namespace std;

lli query(lli t, lli i, lli j, lli k) {
    cout << t << ' ' << i << ' ' << j << ' ' << k << ' ' << '\n';
    cout.flush();
    lli res;
    cin >> res;
    return res;
}

void solve() {
    lli n;
    cin >> n;

    lli t1 = 1;
    lli oo = 5e18;
    vector<pair<lli, lli>> area(n + 1, {-oo, -1});
    for (lli i = 1; i <= n; ++i) area[i].second = i;

    // get t2
    lli t2 = 2;
    for (lli i = 3; i <= n; ++i) {
        lli q2 = query(2, t1, t2, i);
        t2 = (q2 > 0 ? t2 : i);
    }

    // get middle + area
    lli mid = 3, max_s = 0;
    for (lli i = 2; i <= n; ++i) {
        if (i == t2) continue;

        lli q1 = query(1, t1, t2, i);
        area[i].first = q1;

        if (q1 > max_s) {
            max_s = q1;
            mid = i;
        }
    }

    area[mid].first = 0;

    // divide by mid
    for (lli i = 2; i <= n; ++i) {
        if (i == t2 || i == mid) continue;

        lli q2 = query(2, t1, mid, i);

        if (q2 > 0) area[i].first = oo - area[i].first;
        if (q2 < 0) area[i].first = -oo + area[i].first;
    }

    // sort
    sort(area.begin() + 1, area.end());

    cout << "0 ";
    for (lli i = 1; i <= n; ++i)
        cout << area[i].second << (i == n ? '\n' : ' ');

    // for (lli i = 1; i <= n; ++i)
    //     cout << area[i].second << ' ' << area[i].first << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("in", "r", stdin);

    solve();

    return 0;
}