#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const double PI = acos(-1);
const double er = 1e-15;

lli ccw(pair<int, int> v1, pair<int, int> v2) {
    return 1LL * v1.first * v2.second + 1LL * v2.first * v1.second;
}

lli len2(pair<int, int> v) {
    return 1LL * v.first * v.first + 1LL * v.second * v.second;
}

void show_pair(pair<int, int> a) { cout << a.first << ' ' << a.second << '\n'; }

lli scalar(pair<int, int> v1, pair<int, int> v2) {
    return 1LL * (v1.first * v2.first) + 1LL * (v1.second * v2.second);
}

double cos(pair<int, int> v1, pair<int, int> v2) {
    return double(scalar(v1, v2)) / sqrt(len2(v1)) / sqrt(len2(v2));
}

double angle(pair<int, int> v1, pair<int, int> v2) {
    if (ccw(v1, v2) > 0) return acos(cos(v1, v2));
    if (ccw(v1, v2) < 0) return -acos(cos(v1, v2));
    return ((v1.first > 0) & (v2.first > 0) ? 0 : -PI);
}

pair<int, int> vect(pair<int, int> p1, pair<int, int> p2) {
    return {p2.first - p1.first, p2.second - p1.second};
}

bool chk(vector<double> vd) {
    double mn = 1000;
    double mx = -1000;
    for (auto& i : vd) {
        mn = min(mn, i);
        mx = max(mx, i);
    }

    return (PI - (mx - mn)) >= -1e-15;
}

void show_vangle(vector<double>& vangle) {
    sort(vangle.begin(), vangle.end());
    for (auto& i : vangle) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << fixed << setprecision(6) << '\n';
    // freopen("in", "r", stdin);

    pair<int, int> ox{1, 0};
    // pair<int, int> v1{1, 1}, v2{-1, 1}, v3{-1, -1}, v4{1, -1};
    // pair<int, int> v5{1, 0}, v6{0, 1}, v7{-1, 0}, v8{0, -1};

    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> stars(n);
    for (auto& i : stars) cin >> i.second.first >> i.second.second >> i.first;
    sort(stars.rbegin(), stars.rend());

    // for (auto& i : stars)
    //     cout << i.first << ' ' << i.second.first << ' ' << i.second.second
    //          << '\n';

    vector<double> vangle;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (stars[i].first != stars[j].first)
                vangle.push_back(
                    angle(vect(stars[j].second, stars[i].second), ox));
        }
    }

    bool res = chk(vangle);

    // show_vangle(vangle);

    for (auto& i : vangle) i = (i < 0 ? i + PI + PI : i);
    res |= chk(vangle);

    // show_vangle(vangle);

    cout << (res ? "Y\n" : "N\n");

    return 0;
}