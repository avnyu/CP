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

int main() {
    // SPD;
    int n, m;
    cin >> n >> m;
    int lig_kni[n + 1], ned_col[m + 1], rs = 2e6, done = 0, need = 0;
    rep(i, 1, n + 1) cin >> lig_kni[i];
    rep(i, 1, m + 1) cin >> ned_col[i], need += ned_col[i],
        done += ned_col[i] == 0;
    int i = 1, j = 1;
    while (i < n + 1 && j < n + 1) {
        while (i < n + 1 && done != m) {
            ned_col[lig_kni[i]]--;
            if (ned_col[lig_kni[i]] == 0) done++;
            i++;
            // cout<<"TEST1\n";
        }
        while (j < n + 1 && ned_col[lig_kni[j]] < 0 && done == m) {
            ned_col[lig_kni[j]]++;
            j++;
            // cout<<"TEST2\n";
        }
        // rep(k,j,i)cout<<lig_kni[k]<<' ';cout<<'\n';
        if (done == m) rs = min(rs, i - j);
        ned_col[lig_kni[j]]++;
        done--;
        j++;
    }
    if (rs != 2e6)
        cout << rs - need;
    else
        cout << -1;
    return 0;
}
