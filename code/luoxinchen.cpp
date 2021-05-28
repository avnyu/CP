#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000000 + 5;
const int INF = 0x3f3f3f3f;
multiset<int> range, pre;
int a[maxn];
int dp[maxn];  //��1...i������������С�Ļ�����,�����������ΪINF
int n, s, l;
int main() {
    cin >> n >> s >> l;
    for (int i = 1; i < n; i++) { cin >> a[i]; }
    int i = 1, j = 1;
    for (i = 1; i <= n; i++) {
        range.insert(a[i]);
        for (; *range.rbegin() - *range.begin() > s; j++) {
            range.erase(range.find(a[j]));
            if (i - j >= l) pre.erase(pre.find(dp[j - 1]));
        }
        if (i - j + 1 >= l) pre.insert(dp[i - l]);
        if (pre.begin() == pre.end())
            dp[i] = INF;
        else
            dp[i] = *pre.begin() + 1;
    }
    printf("%d\n", dp[n] >= INF ? -1 : dp[n]);
    return 0;
}
