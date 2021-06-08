// In the name of GOD

#include <bits/stdc++.h>

using namespace std;

#define BeGood ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define nl '\n'

typedef long long ll;
typedef double db;

const int N = 2e6 + 101;
const int M = 1e9 + 7;
const int d = 22;

int n, s, k, a[N];
int mx[d][N], mn[d][N];

pair<int, int> check(int l, int r) {
    int cnt = -M, tnc = M;
    for (int i = d; i >= 0; --i) {
        if (l + (1 << i) - 1 <= r) {
            cnt = max(cnt, mx[i][l]);
            tnc = min(tnc, mn[i][l]);
            l += 1 << i;
        }
    }
    return make_pair(cnt, tnc);
}
int main() {
    BeGood

            cin >>
        n >> s >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx[0][i] = mn[0][i] = a[i];
    }
    for (int i = 1; i <= d; ++i) {
        for (int j = 0; j <= n - (1 << i); ++j) {
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
        }
    }
    int LAST = 0;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i) {
        if (i < LAST) {
        } else {
            int l = LAST, r = n;
            int lans = l;
            while (l <= r) {
                int m = (l + r) / 2;
                pair<int, int> ans = check(i, m);
                if (ans.ff - ans.ss <= s) {
                    lans = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            LAST = lans + 1;
            if (lans - i + 1 < k) {
                if (v.size() == 0) {
                    cout << -1;
                    // cout << "1111";
                    return 0;
                }
                int z = v.size() - 1;
                int L = v[z].ff;
                int R = v[z].ss;
                if (R - L + 1 == k) {
                    cout << -1;
                    // cout << "2222";
                    return 0;
                }
                int jet = k - (lans - i + 1);
                if ((R - jet) - L + 1 < k) {
                    cout << -1;
                    // cout << "3333";
                    return 0;
                }
                pair<int, int> ans = check(R - jet + 1, lans);
                if (ans.ff - ans.ss > s) {
                    cout << -1;
                    // cout << "4444";
                    return 0;
                }
                v.pop_back();
                v.push_back({L, R - jet});
                v.push_back({R - jet + 1, lans});
            } else {
                v.push_back({i, lans});
            }
        }
    }
    cout << sz(v);
    return 0;
}
