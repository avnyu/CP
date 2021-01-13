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
    SPD;
    int n;
    cin >> n;
    int a[1001] = {};
    int l, r;
    rep(i, 1, n) {
        cin >> l >> r;
        a[l]++;
        a[r]++;
    }
    int rs = 0;
    rep(i, 1, 1001) rs += a[i] == 1;
    cout << rs;
    return 0;
}
