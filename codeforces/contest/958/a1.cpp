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
#define Spd                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

bool cmp(char a[][100], char b[][100], int len) {
    char chk[8][len][len];
    rep(i, 0, len) rep(j, 0, len) {
        chk[0][i][j] = b[i][j];
        chk[1][i][j] = b[i][len - 1 - j];
        chk[2][i][j] = b[len - 1 - i][j];
        chk[3][i][j] = b[len - 1 - i][len - 1 - j];
        chk[4][i][j] = b[j][i];
        chk[5][i][j] = b[j][len - 1 - i];
        chk[6][i][j] = b[len - 1 - j][i];
        chk[7][i][j] = b[len - 1 - j][len - 1 - i];
    }
    bool match[8] = {};
    rep(i, 0, 8) {
        match[i] = true;
        rep(j, 0, len) { rep(k, 0, len) match[i] &= chk[i][j][k] == a[j][k]; }
    }
    return match[0] | match[1] | match[2] | match[3] | match[4] | match[5] |
           match[6] | match[7];
}
int main() {
    Spd;
    int n;
    cin >> n;
    char a[n][100], b[n][100];
    rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
    rep(i, 0, n) rep(j, 0, n) cin >> b[i][j];
    if (cmp(a, b, n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
