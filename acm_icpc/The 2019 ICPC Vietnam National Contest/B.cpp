#include <bits/stdc++.h>
using namespace std;

int a, b, c, m;
vector<vector<int>> res;
vector<vector<int>> pnt;

void seg_c(int la, int ra, int lb, int rb, int ib, int jb) {
    int ic = ib, jc = ib;
    while (ic < jb) {
        while (jc < jb && pnt[ic][2] == pnt[jc][2]) jc++;
        int lc, rc;

        if (ic == ib)
            lc = 1;
        else
            lc = pnt[ic - 1][2] + 1;

        if (jc == jb)
            rc = c;
        else
            rc = pnt[ic][2];

        res.push_back(vector<int>(7));
        res.back()[0] = pnt[ic][3];
        res.back()[1] = la, res.back()[2] = lb, res.back()[3] = lc;
        res.back()[4] = ra, res.back()[5] = rb, res.back()[6] = rc;

        ic = jc;
    }
}

void seg_b(int la, int ra, int ia, int ja) {
    int ib = ia, jb = ia;
    while (ib < ja) {
        while (jb < ja && pnt[ib][1] == pnt[jb][1]) jb++;
        int lb, rb;

        if (ib == ia)
            lb = 1;
        else
            lb = pnt[ib - 1][1] + 1;

        if (jb == ja)
            rb = b;
        else
            rb = pnt[ib][1];

        seg_c(la, ra, lb, rb, ib, jb);

        ib = jb;
    }
}

void seg_a() {
    int ia = 0, ja = 0;
    while (ia < m) {
        while (ja < m && pnt[ia][0] == pnt[ja][0]) ja++;
        int la, ra;

        if (ia == 0)
            la = 1;
        else
            la = pnt[ia - 1][0] + 1;

        if (ja == m)
            ra = a;
        else
            ra = pnt[ia][0];

        seg_b(la, ra, ia, ja);

        ia = ja;
    }
}

void solve() {
    cin >> b >> c >> m;

    pnt.resize(m, vector<int>(4, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) cin >> pnt[i][j];
        pnt[i][3] = i;
    }

    sort(pnt.begin(), pnt.end());

    cout << "YES\n";

    seg_a();

    sort(res.begin(), res.end());

    for (auto& i : res) {
        for (int j = 1; j < 7; ++j) cout << i[j] << ' ';
        cout << '\n';
    }
    res.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);

    while (1) {
        cin >> a;
        if (a == -1) break;
        solve();
    }

    return 0;
}