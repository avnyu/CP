#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a - 1; i >= b; --i)
#define vi vector<int>
#define piii pair<int, pair<int, int> >
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define m(i, j) map<i, j>
#define F first
#define S second
using namespace std;

int *f = new int[1000001];
void up(int pos, int val, int n) {
    if (pos == 0) return;
    for (int i = pos; i <= n; i += (i & -i)) f[i] += val;
}
int get(int pos) {
    int rs = 0;
    for (int i = pos; i; i -= (i & -i)) rs += f[i];
    return rs;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int *a = new int[n];
    int *l = new int[n];
    int *r = new int[n];
    m(int, int) tl, tr;
    rep(i, 0, n) {
        cin >> a[i];
        l[i] = ++tl[a[i]];
    }
    per(i, n, 0) {
        r[i] = ++tr[a[i]];
        up(r[i], 1, n);
    }
    ll rs = 0;
    rep(i, 0, n) {
        up(r[i], -1, n);
        rs += get(l[i] - 1);
    }
    cout << rs;
    return 0;
}
