#include <bits/stdc++.h>
#define clr(x) memset(x, 0, sizeof(x))
#define clr_1(x) memset(x, -1, sizeof(x))
#define LL long long
#define mod 1000000007
using namespace std;
const int N = 1e7 + 10;
LL maxn, minn, rmaxn, rminn, a[N], s;
int ans;
int n, m, l, flag, ct;
int main() {
    while (scanf("%d%lld%d", &n, &s, &l) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        maxn = minn = a[1];
        flag = 0;
        ans = 0;
        ct = 1;
        for (int i = 2; i <= n; i++) {
            maxn = max(maxn, a[i]);
            minn = min(minn, a[i]);
            ct++;
            if (maxn - minn > s) {
                rmaxn = rminn = a[i - 1];
                if (i - 1 - l < 0) {
                    flag = 1;
                    break;
                }
                for (int j = i - 2; j > i - 1 - l; j--) {
                    rmaxn = max(rmaxn, a[j]);
                    rminn = min(rminn, a[j]);
                    if (rmaxn - rminn > s) {
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
                ans++;
                ct = 1;
                maxn = minn = a[i];
            }
        }
        if (ct >= l)
            ans++;
        else
            flag = 1;
        if (flag)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
