#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn = 2e6 + 100, msiz = 2, mod = 1e9 + 7, inf = 1e9;
int spr1[maxn * 2][20], lg[maxn], a[maxn], n, s, L, spr2[maxn * 2][20],
    mr[maxn], f[maxn], spr3[maxn * 2][20];

int rmq1(int l, int r) {
    int t = lg[r - l + 1];
    return min(spr1[l][t], spr1[r - (1 << t) + 1][t]);
}

int rmq2(int l, int r) {
    int t = lg[r - l + 1];
    return max(spr2[l][t], spr2[r - (1 << t) + 1][t]);
}

int rmq3(int l, int r) {
    int t = lg[r - l + 1];
    return min(spr3[l][t], spr3[r - (1 << t) + 1][t]);
}

int main() {
    // freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> L;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int d = 0, x = i;
        while (x) x >>= 1, d++;
        lg[i] = d - 1;
    }
    for (int i = 0; i < maxn * 2; i++)
        for (int j = 0; j < 20; j++) spr1[i][j] = inf, spr3[i][j] = inf;
    for (int i = 1; i <= n; i++) spr1[i][0] = spr2[i][0] = a[i];
    for (int k = 1; k <= lg[n]; k++)
        for (int i = 1; i <= n; i++)
            spr1[i][k] = min(spr1[i][k - 1], spr1[i + (1 << (k - 1))][k - 1]),
            spr2[i][k] = max(spr2[i][k - 1], spr2[i + (1 << (k - 1))][k - 1]);
    int t = 1;
    // cout<<rmq1(4,4);
    for (int i = 1; i <= n; i++) {
        while (rmq2(i, t) - rmq1(i, t) <= s && t <= n) t++;
        // cout<<rmq2(i,t)<<" "<<rmq1(i,t)<<endl;
        mr[i] = t - 1;
        f[i] = inf;
    }
    // for (int i=1;i<=n;i++) cout<<mr[i]<<endl;
    for (int i = n - L + 1; i; i--) {
        if (mr[i] == n)
            f[i] = 1;
        else if (i + L - 1 <= mr[i] + 1) {
            int tmp = rmq3(i + L - 1, mr[i] + 1);
            // cout<<tmp<<endl;
            if (tmp != inf) f[i] = tmp + 1;
        }
        spr3[i][0] = f[i];
        for (int k = 1; k <= lg[n]; k++)
            spr3[i][k] = min(spr3[i][k - 1], spr3[i + (1 << (k - 1))][k - 1]);
        // cout<<f[i]<<endl;
    }
    if (f[1] == inf)
        cout << -1;
    else
        cout << f[1];
    return 0;
}
