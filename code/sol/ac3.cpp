#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 10000000
#define LL long long
int n, s, l;
int a[MAXN + 5], p[MAXN + 5];
int Max[MAXN + 5], Min[MAXN + 5];
int L2 = 1, R2, L1 = 1, R1, L = 1, R;
int deq[MAXN + 5];
LL dp[MAXN + 5];
int main() {
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int As_p = 1;
    for (int i = 1; i <= n; i++) {
        while (R1 >= L1 && a[Max[L1]] > a[i] + s)
            As_p = Max[L1] + 1, L1++;  //**
        while (R2 >= L2 && a[Min[L2]] < a[i] - s)
            As_p = Min[L2] + 1, L2++;  //**
        p[i] = As_p;
        while (R1 >= L1 && a[Max[R1]] <= a[i]) R1--;
        while (R2 >= L2 && a[Min[R2]] >= a[i]) R2--;
        Max[++R1] = i;
        Min[++R2] = i;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = l; i <= n; i++) {
        while (R >= L && dp[deq[R]] > dp[i - l]) R--;
        deq[++R] = i - l;
        while (R >= L && deq[L] < p[i] - 1) L++;
        if (R >= L) dp[i] = dp[deq[L]] + 1;
    }
    printf("%lld", dp[n] > MAXN ? -1 : dp[n]);  //
}