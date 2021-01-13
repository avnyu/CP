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

int main() {
    Spd;
    int n, m;
    cin >> n >> m;
    int lig_kni[n + 1], ned_col[m + 1], len = 0;
    rep(i, 1, n + 1) cin >> lig_kni[i];
    rep(i, 1, m + 1) cin >> ned_col[i], len += ned_col[i];
    bool chk = true;
    rep(i, 1, len + 1) {
        ned_col[lig_kni[i]]--;
        chk = true;
        rep(j, 1, m + 1) chk &= (ned_col[j] == 0);
        if (chk) {
            cout << "YES";
            return 0;
        }
    }
    rep(i, len + 1, n + 1) {
        ned_col[lig_kni[i]]--;
        ned_col[lig_kni[i - len]]++;
        chk = true;
        rep(j, 1, m + 1) chk &= (ned_col[j] == 0);
        if (chk) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
