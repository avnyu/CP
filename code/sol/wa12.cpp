#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define pb emplace_back
#define F first
#define S second
#define rep(i, st, ed) for (ll i = st; i < ed; ++i)
#define repn(i, st, ed) for (ll i = st; i <= ed; ++i)
#define repb(i, ed, st) for (ll i = ed; i >= st; --i)
#define all(v) v.begin(), v.end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define PI acosl(-1.0)
#define mp(a, b) make_pair(a, b)
#define eps 1e-9
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
typedef long long ll;
template <class T>
void chmax(T &a, T b) {
    if (a < b) a = b;
}
template <class T>
void chmin(T &a, T b) {
    if (a > b) a = b;
}
const int N = 2e6 + 10;
const ll INF = 1LL << 60;

multiset<ll> ms;
ll arr[N], ans[N];
ll seg[4 * N];

void upd(int v, int l, int r, ll val, ll pos) {
    if (l == r)
        seg[v] = val;
    else {
        int mid = (l + r) / 2;
        if (pos <= mid)
            upd(2 * v, l, mid, val, pos);
        else
            upd(2 * v + 1, mid + 1, r, val, pos);
        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    }
}

ll query(int v, int l, int r, int ql, int qr) {
    if (ql > qr) return INT_MAX;
    if (l == ql && r == qr)
        return seg[v];
    else {
        int mid = (l + r) / 2;
        ll ansl = query(2 * v, l, mid, ql, min(qr, mid));
        ll ansr = query(2 * v + 1, mid + 1, r, max(ql, mid + 1), qr);
        return min(ansl, ansr);
    }
}

void solve() {
    int n, s, req;
    cin >> n >> s >> req;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans[i] = INT_MAX;
    }
    ans[n] = 0;
    for (int i = 0; i < 4 * n; i++) seg[i] = INT_MAX;
    int r = n - 1, l = n - 1;
    ms.insert(arr[n - 1]);
    upd(1, 0, n, 0, n);
    while (l >= 0) {
        while ((*ms.rbegin()) - (*ms.begin()) > s) {
            ms.erase(ms.find(arr[r]));
            r--;
        }
        if ((r - l + 1) >= req) {
            ans[l] = query(1, 0, n, l + req, r + 1) + 1LL;
            upd(1, 0, n - 1, ans[l], l);
        }
        l--;
        ms.insert(arr[l]);
    }
    if (ans[0] >= INT_MAX) cout << -1 << endl, exit(0);
    cout << ans[0] << endl;
}

int main() {
    FAST ll Tests = 1;
    // cin>>Tests;
    while (Tests--) { solve(); }
    return 0;
}
