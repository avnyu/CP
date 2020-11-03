#include <bits/stdc++.h>
using namespace std;

const int oo = 60000;
vector<int> t;

void up(int x, int delta) {
    while (x < oo) {
        t[x] += delta;
        x += x & -x;
    }
}

int get(int x) {
    int res = 0;
    while (x > 0) {
        res += t[x];
        x -= x & -x;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; ++i) {
        a[i] = (int) (lower_bound(b.begin(), b.end(), a[i]) - b.begin()) + 1;
    }
    int q;
    cin >> q;
    vector<vector<int>> qr(q, vector<int>(5));
    for (int i = 0; i < q; ++i) {
        cin >> qr[i][0] >> qr[i][1] >> qr[i][2] >> qr[i][3];
        qr[i][0] -= 1;
        qr[i][1] -= 1;
        qr[i][4] = i;
    }
    int block = 250;
    sort(qr.begin(), qr.end(), [&](const vector<int> &i, const vector<int> &j) {
        if (i[0] / block != j[0] / block) {
            return i[0] / block < j[0] / block;
        }
        return i[1] / block < j[1] / block;
    });
    int m = (int) b.size();
    vector<int> cnt(m + 100, 0);
    int lef = 0, rig = 0;
    t.assign(oo + 1, 0);
    cnt[a[0]] += 1;
    up(1, 1);
    vector<int> ans(q, 0);
    for (int i = 0; i < q; ++i) {
        int u = qr[i][0];
        int v = qr[i][1];
        while (lef > u) {
            lef -= 1;
            if (cnt[a[lef]] != 0) {
                up(cnt[a[lef]], -1);
            }
            cnt[a[lef]] += 1;
            up(cnt[a[lef]], 1);
        }
        while (rig < v) {
            rig += 1;
            if (cnt[a[rig]] != 0) {
                up(cnt[a[rig]], -1);
            }
            cnt[a[rig]] += 1;
            up(cnt[a[rig]], 1);
        }
        while (lef < u) {
            if (cnt[a[lef]] != 0) {
                up(cnt[a[lef]], -1);
            }
            cnt[a[lef]] -= 1;
            if (cnt[a[lef]] != 0) {
                up(cnt[a[lef]], 1);
            }
            lef += 1;
        }
        while (rig > v) {
            if (cnt[a[rig]] != 0) {
                up(cnt[a[rig]], -1);
            }
            cnt[a[rig]] -= 1;
            if (cnt[a[rig]] != 0) {
                up(cnt[a[rig]], 1);
            }
            rig -= 1;
        }
        int from = qr[i][2], to = qr[i][3];
        ans[qr[i][4]] = get(to) - get(from - 1);
    }
    for (auto i : ans) {
        cout << i << '\n';
    }
    return 0;
}