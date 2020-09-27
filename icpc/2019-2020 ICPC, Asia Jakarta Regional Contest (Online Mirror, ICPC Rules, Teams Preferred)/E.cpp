#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    // freopen("in", "r", stdin);

    int n, l, r, k;
    int N = 1e5 + 7;
    vector<int> a(N), res(N);
    vector<long long> ub(N), lb(N), mnub(N), mxlb(N);

    cin >> n >> l >> r >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = n - 1; i; --i) {
        if (a[i] > a[i - 1])
            a[i] = 1;
        else if (a[i] == a[i - 1])
            a[i] = 0;
        else
            a[i] = -1;
    }
    a[0] = 0;

    for (int i = 1; i < n; ++i) {
        if (a[i] == 1) {
            ub[i] = ub[i - 1] + k;
            lb[i] = lb[i - 1] + 1;
        } else if (a[i] == -1) {
            ub[i] = ub[i - 1] - 1;
            lb[i] = lb[i - 1] - k;
        } else {
            ub[i] = ub[i - 1];
            lb[i] = lb[i - 1];
        }
    }

    mnub[n - 1] = ub[n - 1];
    mxlb[n - 1] = lb[n - 1];
    for (int i = n - 1; i; --i) {
        mnub[i - 1] = min(mnub[i], ub[i - 1]);
        mxlb[i - 1] = max(mxlb[i], lb[i - 1]);
    }

    // debug

    // for (int i = 0; i < n; ++i) std::cout << lb[i] << ' ';
    // std::cout << '\n';
    // for (int i = 0; i < n; ++i) std::cout << ub[i] << ' ';
    // std::cout << '\n';
    // for (int i = 0; i < n; ++i) std::cout << mxlb[i] << ' ';
    // std::cout << '\n';
    // for (int i = 0; i < n; ++i) std::cout << mnub[i] << ' ';
    // std::cout << '\n';

    bool chk = true;
    int lx = l, rx = r;
    for (int i = 0; i < n; ++i) {
        if (i) {
            if (a[i] == 1) {
                lx = max(res[i - 1] + 1, l);
                rx = min(res[i - 1] + k, r);
            } else if (a[i] == 0) {
                lx = rx = res[i - 1];
            } else {
                lx = max(res[i - 1] - k, l);
                rx = min(res[i - 1] - 1, r);
            }
        }

        if (lx > rx) {
            chk = false;
            break;
        }

        chk = false;
        while (lx <= rx) {
            int mx = (lx + rx) >> 1;
            int nlb = mx + mxlb[i] - lb[i];
            int nub = mx + mnub[i] - ub[i];

            // std::cout << "test " << mx << ' ' << i << ' ' << nlb << ' ' << nub
                    //   << '\n';

            if (nub >= l && nlb <= r) {
                chk = true;
                res[i] = mx;
                rx = mx - 1;
            } else if (nlb > r) {
                rx = mx - 1;
            } else
                lx = mx + 1;
        }

        if (!chk) break;
    }

    if (!chk) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) std::cout << res[i] << ' ';
    std::cout << '\n';

    return 0;
}