#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> va, vd, vh;
    for (long long i = 0; i < n; ++i) {
        long long a, d, h;
        cin >> a >> d >> h;
        va.push_back({a, i});
        vd.push_back({d, i});
        vh.push_back({h, i});
    }

    sort(va.begin(), va.end(), greater<pair<long long, long long>>());
    sort(vd.begin(), vd.end(), greater<pair<long long, long long>>());
    sort(vh.begin(), vh.end(), greater<pair<long long, long long>>());

    set<long long> res;
    for (long long i = 0; i < k; ++i) {
        res.insert(va[i].second);
        res.insert(vd[i].second);
        res.insert(vh[i].second);
    }

    cout << res.size() << '\n';

    return 0;
}