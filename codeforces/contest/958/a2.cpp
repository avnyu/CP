#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a - 1; i >= b; --i)
#define vi vector<int>
#define piii pair<int, pair<int, int> >
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define SPD                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

bool chk(char a[2000][200], char b[200][2000], int x, int y, int m) {
    rep(i, 0, m) rep(j, 0, m) {
        if (a[i + x][j] != b[i][j + y]) return false;
    }
    return true;
}
int main() {
    SPD;
    int n, m;
    cin >> n >> m;
    map<int, vi> a;
    int tmp[n] = {}, sum = 0, sum_tmp = 0;
    char table_a[2000][200], table_b[200][2000];
    rep(i, 0, n) {
        rep(j, 0, m) cin >> table_a[i][j],
            tmp[i] += (j + 1) * (table_a[i][j] - 'a' + 1);
    }
    rep(i, 0, m) {
        sum += tmp[i] * (i + 1);
        sum_tmp += tmp[i];
    }
    a[sum].pb(0);
    // cout<<sum<<'\n';
    rep(i, m, n) {
        sum += tmp[i] * m - sum_tmp;
        sum_tmp += tmp[i] - tmp[i - m];
        a[sum].pb(i - m + 1);
        // cout<<sum<<'\n';
    }
    // cout<<'\n';
    rep(i, 0, m) rep(j, 0, n) cin >> table_b[i][j];
    int tmp1[n] = {};
    rep(i, 0, n) {
        rep(j, 0, m) tmp1[i] += (table_b[j][i] - 'a' + 1) * (j + 1);
    }
    sum = 0, sum_tmp = 0;
    rep(i, 0, m) {
        sum += tmp1[i] * (i + 1);
        sum_tmp += tmp1[i];
    }
    // cout<<sum<<'\n';
    if (!a[sum].empty()) {
        rep(i, 0, a[sum].size()) if (chk(table_a, table_b, a[sum][i], 0, m)) {
            cout << a[sum][i] + 1 << ' ' << 1;
            return 0;
        }
    }
    rep(i, m, n) {
        sum += tmp1[i] * m - sum_tmp;
        // cout<<sum<<'\n';
        sum_tmp += tmp1[i] - tmp1[i - m];
        if (!a[sum].empty()) {
            rep(j, 0, a[sum].size()) {
                if (chk(table_a, table_b, a[sum][j], i - m + 1, m)) {
                    cout << a[sum][j] + 1 << ' ' << i - m + 2;
                    return 0;
                }
            }
        }
    }
    return 0;
}
