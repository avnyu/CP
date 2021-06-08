#include <iostream>
#include <set>
using namespace std;
const int maxn = 2e6 + 5;
const int inf = 0x3f3f3f;
int a[maxn], dp[maxn];
int main() {
    int n, s, l;
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    multiset<int> pre, cur;
    int i = 1, j = 1;
    for (i = 1; i <= n; i++) {
        cur.insert(a[i]);
        while (*cur.rbegin() - *cur.begin() > s) {
            cur.erase(cur.find(a[j]));
            if (pre.find(dp[j - 1]) != pre.end()) {
                pre.erase(pre.find(dp[j - 1]));
            }
            j++;
        }
        if (i - j + 1 >= l) {
            if (pre.find(dp[j - 1]) == pre.end()) pre.insert(dp[j - 1]);
        }
        if (pre.empty())
            dp[i] = inf;
        else
            dp[i] = *pre.begin() + 1;
    }
    int ans = dp[n];
    if (ans >= inf) ans = -1;
    printf("%d\n", ans);
    return 0;
}
