#include <bits/stdc++.h>
#define L(p) lower_bound(A + 1, A + n + 1, p)
#define for (n) for (int i = 1; i <= n; i++)
using namespace std;
long long x, n, k, A[100010], lw, up, ans;

main() {
    scanf("%lld%lld%lld", &n, &x, &k);
    for (n) scanf("%lld", &A[i]);
    sort(A + 1, A + n + 1);
    for (n) {
        lw = x * ((A[i] + x - 1) / x + k - 1);
        up = lw + x;
        lw = lw < A[i] ? A[i] : lw;
        // cout << lw << "-" << up << endl;
        ans += L(up) - L(lw);
    }
    printf("%lld", ans);
}
