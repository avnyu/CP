#include <time.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#define maxn 10000005
#define maxm 20000005
#define eps 1e-10
#define mod 1000000007
#define INF 0x3f3f3f3f
#define PI (acos(-1.0))
#define lowbit(x) (x & (-x))
#define mp make_pair
#define ls o << 1
#define rs o << 1 | 1
#define lson o << 1, L, mid
#define rson o << 1 | 1, mid + 1, R
#define pii pair<int, int>
//#pragma comment(linker, "/STACK:16777216")
typedef long long LL;
typedef unsigned long long ULL;
// typedef int LL;
using namespace std;
LL qpow(LL a, LL b) {
    LL res = 1, base = a;
    while (b) {
        if (b % 2) res = res * base;
        base = base * base;
        b /= 2;
    }
    return res;
}
LL powmod(LL a, LL b) {
    LL res = 1, base = a;
    while (b) {
        if (b % 2) res = res * base % mod;
        base = base * base % mod;
        b /= 2;
    }
    return res;
}
void scanf(int &__x) {
    __x = 0;
    char __ch = getchar();
    while (__ch == ' ' || __ch == '\n') __ch = getchar();
    while (__ch >= '0' && __ch <= '9')
        __x = __x * 10 + __ch - '0', __ch = getchar();
}
// head

deque<pii> mx, mi;
int dp[maxn];
int a[maxn];
int n, s, l;

void read(void) {
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void work(void) {
    dp[0] = 0;
    for (int i = 1, p = 1; i <= n; i++) {
        while (!mx.empty() && mx.back().first <= a[i]) mx.pop_back();
        while (!mi.empty() && mi.back().first >= a[i]) mi.pop_back();
        mx.push_back(mp(a[i], i));
        mi.push_back(mp(a[i], i));
        while (p < i &&
               (dp[p - 1] == -1 || mx.front().first - mi.front().first > s)) {
            p++;
            while (mx.front().second < p) mx.pop_front();
            while (mi.front().second < p) mi.pop_front();
        }
        if (i - p + 1 < l || dp[p - 1] == -1)
            dp[i] = -1;
        else
            dp[i] = dp[p - 1] + 1;
    }
    printf("%d\n", dp[n]);
}

int main(void) {
    read();
    work();

    return 0;
}
