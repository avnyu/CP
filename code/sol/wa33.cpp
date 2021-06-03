#include <assert.h>
#include <stdlib.h>

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
typedef long long ll;
#define MAX 100005
using namespace std;
#define INF 2147483647
#define infL (1LL << 60)
#define inf (1 << 30)
#define MOD 1000000007
#define EPS 1e-9
#define Gr 9.8
#define PI acos(-1)
#define REP(i, n) for (int(i) = 0; (i) < (int)(n); (i)++)
#define REQ(i, n) for (int(i) = 1; (i) <= (int)(n); (i)++)
#define lch (rt << 1)
#define rch (rt << 1 | 1)
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
ll ln, lk, lm;

int a[MAX], s, l;
int cnt, x[MAX], y[MAX], st[MAX];
bool ck() {
    REQ(i, cnt) {
        int ed = i == cnt ? n : st[i + 1] - 1;
        if (i > 1) {
            int last = st[i - 1];
            for (int j = st[i] - 1; j - last >= l; j--) {
                if (abs(a[j] - x[i]) > s || abs(a[j] - y[i]) > s) {
                    break;
                } else {
                    st[i]--;
                    x[i] = min(x[i], a[j]);
                    y[i] = max(y[i], a[j]);
                }
            }
        }
        if (ed - st[i] + 1 < l) return 0;
        // cout<<ed - st[i]+1<<endl;
    }
    return 1;
}
int main() {
    scanf("%d%d%d", &n, &s, &l);
    REQ(i, n) { scanf("%d", a + i); }
    cnt = 1;
    x[1] = a[1];
    y[1] = a[1];
    st[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (abs(a[i] - x[cnt]) > s || abs(a[i] - y[cnt]) > s) {
            st[cnt + 1] = i;
            cnt++;
            x[cnt] = a[i];
            y[cnt] = a[i];
        } else {
            x[cnt] = min(x[cnt], a[i]);
            y[cnt] = max(y[cnt], a[i]);
        }
    }
    if (ck())
        printf("%d\n", cnt);
    else
        puts("-1");
    return 0;
}
