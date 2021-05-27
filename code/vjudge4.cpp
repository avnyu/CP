#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define eps 1e-10
#define INF 1 << 30
using namespace std;
#define maxn 10000005
int q1[maxn];  // xiajie
int q2[maxn];  // shangjie
int dp[maxn];
int a[maxn];
int main() {
    memset(dp, -1, sizeof(dp));
    int head1 = 0, tail1 = 0;
    int head2 = 0, tail2 = 0;
    dp[0] = 0;
    int ans = -1;
    int n, s, l;
    scanf("%d%d%d", &n, &s, &l);
    int t = 0;
    int tt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        while (head1 < tail1 && a[q1[tail1 - 1]] > a[i]) tail1--;
        while (head1 < tail1 && a[i] - a[q1[head1]] > s) {
            t = max(t, q1[head1]);
            head1++;
        }
        q1[tail1++] = i;
        while (head2 < tail2 && a[q2[tail2 - 1]] < a[i]) tail2--;
        while (head2 < tail2 && a[q2[head2]] - a[i] > s) {
            t = max(t, q2[head2]);
            head2++;
        }
        q2[tail2++] = i;
        if (i - t >= l) {
            if (tt > t) {
                dp[i] = dp[tt] + 1;
                continue;
            }
            int j;
            for (j = t; j <= i - l; j++) {
                if (dp[j] != -1) {
                    dp[i] = dp[j] + 1;
                    tt = j;
                    break;
                }
            }
            if (j > i - l) dp[i] = -1;
        } else {
            dp[i] = -1;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
